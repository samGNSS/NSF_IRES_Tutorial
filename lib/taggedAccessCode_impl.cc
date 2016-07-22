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
#include "taggedAccessCode_impl.h"

#define accessCode1 '\xB7'
#define accessCode2 '\x97'
#define accessCode3 '\x12'
#define accessCode4 '\xF9'
#define accessCode5 '\xAF'
#define accessCode6 '\x2D'
#define accessCode7 '\xF9'
#define accessCode8 '\xAF'
// #define accessCode9 '\x12'


namespace gr {
  namespace lets_test_some_stuff {

    taggedAccessCode::sptr
    taggedAccessCode::make()
    {
      return gnuradio::get_initial_sptr
        (new taggedAccessCode_impl());
    }

    /*
     * The private constructor
     */
    taggedAccessCode_impl::taggedAccessCode_impl()
      : gr::tagged_stream_block("taggedAccessCode",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)), "packet_len")
    {}

    /*
     * Our virtual destructor.
     */
    taggedAccessCode_impl::~taggedAccessCode_impl()
    {
    }

    int
    taggedAccessCode_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      return ninput_items[0] + 8;
    }

    int
    taggedAccessCode_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      char *out = (char *) output_items[0];
      long packet_length = ninput_items[0];
      //append access code
      //Do header stuff
      char *accessBuff = new char[8]; //8 byte access code header
      //fill the buffer: store the packet number then length all as MSB first
      accessBuff[0] = accessCode1;
      accessBuff[1] = accessCode2;
      accessBuff[2] = accessCode3;
      accessBuff[3] = accessCode4;
      accessBuff[4] = accessCode5;
      accessBuff[5] = accessCode6;
      accessBuff[6] = accessCode7;
      accessBuff[7] = accessCode8;
      // accessBuff[8] = accessCode9;

      //fill output buffer
      std::memcpy(out,accessBuff,8); //put header at the top
      std::memcpy(out+8,in,packet_length); //fill the packet after the header

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
      delete[] accessBuff;
      // Tell runtime system how many output items we produced.
      return packet_length + 8;
    }

  } /* namespace lets_test_some_stuff */
} /* namespace gr */
