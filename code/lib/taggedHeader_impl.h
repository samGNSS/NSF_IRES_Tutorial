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

#ifndef INCLUDED_LETS_TEST_SOME_STUFF_TAGGEDHEADER_IMPL_H
#define INCLUDED_LETS_TEST_SOME_STUFF_TAGGEDHEADER_IMPL_H

#include <lets_test_some_stuff/taggedHeader.h>

namespace gr {
  namespace lets_test_some_stuff {

    class taggedHeader_impl : public taggedHeader
    {
     private:
       unsigned short d_packetNumber;
       unsigned short d_msgType;
       short unsigned int getMsgType(gr_vector_int &ninput_items,gr_vector_const_void_star &input_items);
     protected:
       int calculate_output_stream_length(const gr_vector_int &ninput_items);

     public:
      taggedHeader_impl();
      ~taggedHeader_impl();

      // Where all the action really happens
      int work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace lets_test_some_stuff
} // namespace gr

#endif /* INCLUDED_LETS_TEST_SOME_STUFF_TAGGEDHEADER_IMPL_H */
