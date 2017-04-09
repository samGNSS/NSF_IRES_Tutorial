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


#ifndef INCLUDED_LETS_TEST_SOME_STUFF_TAGGEDHEADER_H
#define INCLUDED_LETS_TEST_SOME_STUFF_TAGGEDHEADER_H

#include <lets_test_some_stuff/api.h>
#include <gnuradio/tagged_stream_block.h>

namespace gr {
  namespace lets_test_some_stuff {

    /*!
     * \brief <+description of block+>
     * \ingroup lets_test_some_stuff
     *
     */
    class LETS_TEST_SOME_STUFF_API taggedHeader : virtual public gr::tagged_stream_block
    {
     public:
      typedef boost::shared_ptr<taggedHeader> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of lets_test_some_stuff::taggedHeader.
       *
       * Appends a header to a stream of data
       */
      static sptr make();
    };

  } // namespace lets_test_some_stuff
} // namespace gr

#endif /* INCLUDED_LETS_TEST_SOME_STUFF_TAGGEDHEADER_H */

