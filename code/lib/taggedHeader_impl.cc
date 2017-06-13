/* -*- c++ -*- */
/*
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "taggedHeader_impl.h"

#define headerLength 6 //bytes
#define numZeros     100

namespace gr {
  namespace lets_test_some_stuff {

    taggedHeader::sptr
    taggedHeader::make()
    {
      return gnuradio::get_initial_sptr
        (new taggedHeader_impl());
    }

    taggedHeader_impl::taggedHeader_impl()
      : gr::tagged_stream_block("taggedHeader",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)), "packet_len"),
              d_packetNumber(0)
	      {}

    taggedHeader_impl::~taggedHeader_impl(){}

    int
    taggedHeader_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      return ninput_items[0] + headerLength; //add four bytes for the header
    }

    int
    taggedHeader_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      char *out = (char *) output_items[0];
      /*
       * Header structure:
       *  - packet length, stored as two bytes, repeated twice
       *  - packet number, stored as one byte, gives in indication on whether or not we dropped a packet
       *  - packet type, stored as one byte, tells the rx what kind of data we received
       * 	- current choices are:
       * 		0x00 -> pad buffer
       *                0x01 -> data buffer
       */
      d_msgType = getMsgType(ninput_items,input_items);
      int payLoadLen = ninput_items[0] + 2; //adjust packet length by 2 for the packet length and message type
      char header[] = {0xFF&(payLoadLen>>8),0xFFFF&payLoadLen,0xFF&(payLoadLen>>8),0xFFFF&payLoadLen,0xFF&d_packetNumber,0xFF&d_msgType}; //6 bytes
           
      //fill output buffer
      std::memcpy(out,header,headerLength); //put header at the top
      std::memcpy(out+headerLength,in,ninput_items[0]); //fill the packet after the header
      d_packetNumber++;
      /*
      Rearange the tags
      */
      std::vector <tag_t> tags;
      get_tags_in_range(tags, 0, nitems_read(0), nitems_read(0) + ninput_items[0]);
      for (size_t i = 0; i < tags.size(); ++i) {
        tags[i].offset -= nitems_read(0);
	if (tags[i].offset > (unsigned int) (ninput_items[0] + headerLength)) {
          tags[i].offset = ninput_items[0] - headerLength - 1;
	}
        add_item_tag(0, nitems_written(0) + tags[i].offset,tags[i].key,tags[i].value);
      }
      
      // Tell runtime system how many output items we produced.
      return ninput_items[0] + headerLength;
    }
    
  short unsigned int taggedHeader_impl::getMsgType(gr_vector_int& ninput_items,gr_vector_const_void_star &input_items){
    //HACK: look at a part of the input buffer and count the number of zeros
    const char *in = (const char *) input_items[0];
    int midPoint = (ninput_items[0]-1)/2;
    int zeroCount = 0;
    for(int i=0;i<numZeros;++i){
      in[i+midPoint] == 0 ? ++zeroCount:0;
    }
    
    if(zeroCount>=numZeros){
      return 0x0000;
    }else{
      return 0x0001;
    }
  }


  } /* namespace lets_test_some_stuff */
} /* namespace gr */
