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
#include "taggedHeaderParser_impl.h"

#define headerSize 2
#define debug

namespace gr {
  namespace lets_test_some_stuff {

    taggedHeaderParser::sptr
    taggedHeaderParser::make()
    {
      return gnuradio::get_initial_sptr
        (new taggedHeaderParser_impl());
    }

    taggedHeaderParser_impl::taggedHeaderParser_impl()
      : gr::tagged_stream_block("taggedHeaderParser",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)), "packet_len"),d_prevPacketNumber(0)
	      {}

    taggedHeaderParser_impl::~taggedHeaderParser_impl(){}

    int
    taggedHeaderParser_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      return ninput_items[0] - headerSize; //subtract two bytes for the header
    }

    int
    taggedHeaderParser_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      char *out = (char *) output_items[0];
      uint8_t header[] = {0,0}; //two bytes for the header

      //parse header
      std::memcpy(header,in,headerSize);

      //check for dropped packets
      ++d_prevPacketNumber %= 256;
      if(d_prevPacketNumber != header[0]){
        printf("WARNING: Packet Loss Detected\nExpected packet number: %d got %d\n",d_prevPacketNumber,header[0]);
        d_prevPacketNumber = header[0];
      }

       //wrap packet counter
       //d_prevPacketNumber %= 256;

      /*
       * Header structure:
       *  - packet length, stored as two bytes, repeated twice
       *  - packet number, stored as one byte, gives in indication on whether or not we dropped a packet
       *  - packet type, stored as one byte, tells the rx what kind of data we received
       * 	- current choices are:
       * 		0x00 -> pad buffer, drop on the floor
       *                0x01 -> data buffer, strip the header and pass on
       */
      switch(header[1]){
        case 0:{
            //got a pad buffer, drop it on the floor
            #ifdef debug
            	printf("packet type: %x\n",header[1]);
            #endif
            return 0;
        }
        case 1:{
            //data packet
            break;
        }
        default:{
            printf("Bad Packet\n");
            return 0;
        }
      }

      //fill output buffer
       std::memcpy(out,in+headerSize,ninput_items[0] - headerSize); //fill the packet after the header

      /*
      Rearange the tags
      */
      std::vector <tag_t> tags;
      get_tags_in_range(tags, 0, nitems_read(0), nitems_read(0) + ninput_items[0]);
      for (size_t i = 0; i < tags.size(); ++i){
        tags[i].offset -= nitems_read(0);
        if (tags[i].offset > (unsigned int) (ninput_items[0])) {
            tags[i].offset = ninput_items[0] - 1;
        }
        add_item_tag(0, nitems_written(0) + tags[i].offset,tags[i].key,tags[i].value);
      }

      // Tell runtime system how many output items we produced.
      return ninput_items[0] - headerSize;
    }

  } /* namespace lets_test_some_stuff */
} /* namespace gr */
