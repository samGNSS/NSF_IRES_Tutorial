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

namespace gr {
  namespace lets_test_some_stuff {

    taggedHeader::sptr
    taggedHeader::make()
    {
      return gnuradio::get_initial_sptr
        (new taggedHeader_impl());
    }

    /*
     * The private constructor
     */
    taggedHeader_impl::taggedHeader_impl()
      : gr::tagged_stream_block("taggedHeader",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)), "packet_len"),
              d_packetNumber(0)
    {}

    /*
     * Our virtual destructor.
     */
    taggedHeader_impl::~taggedHeader_impl()
    {
    }

    int
    taggedHeader_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      return ninput_items[0] + 4; //add four bytes for the header
    }

    int
    taggedHeader_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      char *out = (char *) output_items[0];
      long packet_length = ninput_items[0];
      //Do header stuff
      char *headerBuff = new char[4]; //4 byte header
      //fill the buffer: store the packet number then length all as MSB first
      // headerBuff[0] = 0x0FF & (d_packetNumber >> 8); //upper byte of packNumber
      // headerBuff[1] = 0x0FF & (d_packetNumber); //lower byte of packNumber
      headerBuff[0] = 0x0FF & (packet_length >> 8); //upper byte of noutput_items (packet size)
      headerBuff[1] = 0x0FF & (packet_length); //lower byte of noutput_items (pcket size)
      headerBuff[2] = 0x0FF & (packet_length >> 8); //upper byte of noutput_items (packet size)
      headerBuff[3] = 0x0FF & (packet_length); //lower byte of noutput_items (pcket size)

      //fill output buffer
      std::memcpy(out,headerBuff,4); //put header at the top
      std::memcpy(out+4,in,packet_length); //fill the packet after the header
      d_packetNumber++;
      /*
      Rearange the tags
      */
      std::vector <tag_t> tags;
      get_tags_in_range(tags, 0, nitems_read(0), nitems_read(0) + packet_length);
      for (size_t i = 0; i < tags.size(); i++) {
        tags[i].offset -= nitems_read(0);
        add_item_tag(0, nitems_written(0) + tags[i].offset,tags[i].key,tags[i].value);
        //probably need to move the memcpy code into this loop...
      }
      delete[] headerBuff;
      // Tell runtime system how many output items we produced.
      return packet_length + 4;
    }

  } /* namespace lets_test_some_stuff */
} /* namespace gr */
