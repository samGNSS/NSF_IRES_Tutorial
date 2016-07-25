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
#include "taggedPacketGate_impl.h"

namespace gr {
  namespace lets_test_some_stuff {

    taggedPacketGate::sptr
    taggedPacketGate::make(const std::string &tagName)
    {
      return gnuradio::get_initial_sptr
        (new taggedPacketGate_impl(tagName));
    }

    /*
     * The private constructor
     */
    taggedPacketGate_impl::taggedPacketGate_impl(const std::string &tagName)
      : gr::block("taggedPacketGate",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(char))),
              d_tagName(tagName)
    {}

    /*
     * Our virtual destructor.
     */
    taggedPacketGate_impl::~taggedPacketGate_impl()
    {
    }

    void
    taggedPacketGate_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      unsigned ninputs = ninput_items_required.size();
      for(unsigned i = 0; i < ninputs; i++)
        ninput_items_required[i] = noutput_items;
    }

    int
    taggedPacketGate_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const char *in = (const char *) input_items[0];
      char *out = (char *) output_items[0];

      // Do <+signal processing+>
      //Look for tags in the input buffer and only pass samples with a tag
      std::vector <tag_t> tags;
      get_tags_in_range(tags, 0, nitems_read(0), nitems_read(0) + noutput_items);
      if (tags.size() > 0)
      {
        //std::cout << tags.size() << std::endl;
        //tags found, copy input buffer to output buffer
        /*
        Need to add code to detect which tags are present
        */

        std::memcpy(out,in,noutput_items);

        // Tell runtime system how many input items we consumed on
        // each input stream.
        consume_each (noutput_items);
        // Tell runtime system how many output items we produced.
        return noutput_items;
      }
      else
      {
        //no tags found, drop the samples
        // Tell runtime system how many input items we consumed on
        // each input stream.
        consume_each (noutput_items);
        // Tell runtime system how many output items we produced.
        return 0;
      }
    }

  } /* namespace lets_test_some_stuff */
} /* namespace gr */
