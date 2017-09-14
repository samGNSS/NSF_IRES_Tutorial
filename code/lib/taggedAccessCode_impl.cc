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

#define accessCode "\xB7\x97\x12\xF9\xAF\x2D\xF9\xAF"
#define codeLength 8 //bytes

namespace gr {
  namespace lets_test_some_stuff {

    taggedAccessCode::sptr
    taggedAccessCode::make()
    {
      return gnuradio::get_initial_sptr
        (new taggedAccessCode_impl());
    }

    taggedAccessCode_impl::taggedAccessCode_impl()
      : gr::tagged_stream_block("taggedAccessCode",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char)), "packet_len")
    {}

    taggedAccessCode_impl::~taggedAccessCode_impl(){}

    //tell the run time system (scheduler) that we will return ninput_items + 8 output items
    int
    taggedAccessCode_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      return ninput_items[0] + codeLength;
    }


    //append the access code to the input stream
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
      std::memmove(out,accessCode,codeLength);

      //fill the packet after the header
      std::memmove(out+codeLength,in,packet_length);

      /*
      Rearange the tags
      */
      std::vector <tag_t> tags;
      get_tags_in_range(tags, 0, nitems_read(0), nitems_read(0) + packet_length);
      for (size_t i = 0; i < tags.size(); i++) {
        tags[i].offset -= nitems_read(0);
	if (tags[i].offset > (unsigned int) (ninput_items[0] + codeLength)) {
          tags[i].offset = ninput_items[0] - codeLength - 1;
	}
        add_item_tag(0, nitems_written(0) + tags[i].offset,tags[i].key,tags[i].value);
      }

      // Tell runtime system how many output items we produced.
      return packet_length + codeLength;
    }

  } /* namespace lets_test_some_stuff */
} /* namespace gr */
