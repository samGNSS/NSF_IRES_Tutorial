/* -*- c++ -*- */
/*
 * Copyright 2012 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/thread/thread.h>
#include "taggedFileSource_impl.h"
#include <gnuradio/io_signature.h>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include <stdio.h>

// win32 (mingw/msvc) specific
#ifdef HAVE_IO_H
#include <io.h>
#endif
#ifdef O_BINARY
#define	OUR_O_BINARY O_BINARY
#else
#define	OUR_O_BINARY 0
#endif
// should be handled via configure
#ifdef O_LARGEFILE
#define	OUR_O_LARGEFILE	O_LARGEFILE
#else
#define	OUR_O_LARGEFILE 0
#endif

namespace gr {
  namespace lets_test_some_stuff {

    taggedFileSource::sptr taggedFileSource::make(size_t itemsize, const char *filename, bool repeat, int blockLength)
    {
      return gnuradio::get_initial_sptr
	(new taggedFileSource_impl(itemsize, filename, repeat,blockLength));
    }

    taggedFileSource_impl::taggedFileSource_impl(size_t itemsize, const char *filename, bool repeat, int blockLength)
      : sync_block("taggedFileSource",
		      io_signature::make(0, 0, 0),
		      io_signature::make(1, 1, itemsize)),
	d_itemsize(itemsize), d_fp(0), d_new_fp(0), d_repeat(repeat),
	d_updated(false),
  d_blockLength(blockLength)
    {
      open(filename, repeat);
      do_update();
      d_packet_len_pmt = pmt::from_long(d_blockLength);
      d_len_tag_key = pmt::string_to_symbol("packet_len");
      d_next_tag_pos = 0;
      endFlag = 0;
      startFlag = 1;
      pad = new char[d_blockLength];
      std::memset(pad,0,d_blockLength); //get an array of zeros
    }

    taggedFileSource_impl::~taggedFileSource_impl()
    {
      delete[] pad;
      if(d_fp)
        fclose ((FILE*)d_fp);
      if(d_new_fp)
        fclose ((FILE*)d_new_fp);
    }

    bool
    taggedFileSource_impl::seek(long seek_point, int whence)
    {
      return fseek((FILE*)d_fp, seek_point *d_itemsize, whence) == 0;
    }


    void
    taggedFileSource_impl::open(const char *filename, bool repeat)
    {
      // obtain exclusive access for duration of this function
      gr::thread::scoped_lock lock(fp_mutex);

      int fd;

      // we use "open" to use to the O_LARGEFILE flag
      if((fd = ::open(filename, O_RDONLY | OUR_O_LARGEFILE | OUR_O_BINARY)) < 0) {
        	perror(filename);
        	throw std::runtime_error("can't open file");
      }

      if(d_new_fp) {
        	fclose(d_new_fp);
        	d_new_fp = 0;
      }

      if((d_new_fp = fdopen (fd, "rb")) == NULL) {
        	perror(filename);
        	::close(fd);	// don't leak file descriptor if fdopen fails
        	throw std::runtime_error("can't open file");
      }

      d_updated = true;
      d_repeat = repeat;
    }

    void
    taggedFileSource_impl::close()
    {
      // obtain exclusive access for duration of this function
      gr::thread::scoped_lock lock(fp_mutex);

      if(d_new_fp != NULL) {
        	fclose(d_new_fp);
        	d_new_fp = NULL;
      }
      d_updated = true;
    }

    void
    taggedFileSource_impl::do_update()
    {
      if(d_updated) {
        	gr::thread::scoped_lock lock(fp_mutex); // hold while in scope

        	if(d_fp)
        	  fclose(d_fp);

        	d_fp = d_new_fp;    // install new file pointer
        	d_new_fp = 0;
        	d_updated = false;
        }
    }

    int
    taggedFileSource_impl::work(int noutput_items,
			   gr_vector_const_void_star &input_items,
			   gr_vector_void_star &output_items)
    {
      char *o = (char*)output_items[0];
      int i;
      int size = noutput_items;

      do_update();       // update d_fp is reqd
      if(d_fp == NULL)
	     throw std::runtime_error("work with file not open");

      //gr::thread::scoped_lock lock(fp_mutex); // hold for the rest of this function

      //check start flag
      if(startFlag)
      {
        //first output packet will be all zeros
        //char *zeros = new char[d_blockLength];
        //std::memset(zeros,0,d_blockLength); //init with zeros
        std::memcpy(o,pad,d_blockLength); //copy to output buffer
        /*
        Get tags
        */
        //std::cout << nitems_written(0) << std::endl;
        while(d_next_tag_pos < nitems_written(0) + d_blockLength) {
          add_item_tag(0, d_next_tag_pos, d_len_tag_key, d_packet_len_pmt);
          d_next_tag_pos += d_blockLength;
        }
        startFlag = 0; //clear start flag
        return d_blockLength; //return
      }

      while(size) {
	       i = fread(o, d_itemsize, size, (FILE*)d_fp);

	      size -= i;
	      o += i * d_itemsize;

      	if(size == 0)		// done
      	  break;

      	if(i > 0)			// short read, try again
      	  continue;

      	// We got a zero from fread.  This is either EOF or error.  In
      	// any event, if we're in repeat mode, seek back to the beginning
      	// of the file and try again, else break
      	if(!d_repeat)
        {
          std::cout << "WTF? lrn2ply! " << "Size is " << size << std::endl;
      	  break;
        }
      	if(fseek ((FILE *) d_fp, 0, SEEK_SET) == -1) {
      	  fprintf(stderr, "[%s] fseek failed\n", __FILE__);
      	  exit(-1);
      	}
      }

      if(size > 0) {	     		// EOF or error
        //std::cout << "here" << std::endl;
	       if((size == noutput_items) && (endFlag < 4))
         {
            if (noutput_items < d_blockLength)
              std::cout << "Thats a 50 dkp minus" << std::endl;
            // we didn't read anything, assume we are at the end of the file and pad with zeros
            std::memcpy(o,pad,d_blockLength);
            while(d_next_tag_pos < nitems_written(0) + d_blockLength) {
             add_item_tag(0, d_next_tag_pos, d_len_tag_key, d_packet_len_pmt);
             d_next_tag_pos += d_blockLength;
            }
            endFlag++;
            std::cout << endFlag << std::endl;
  	        return noutput_items;
           }
           else if (endFlag >= 4)
          {return -1;}
        // while(d_next_tag_pos < nitems_written(0) + d_blockLength) {
        //  add_item_tag(0, d_next_tag_pos, d_len_tag_key, d_packet_len_pmt);
        //  std::cout << "Many welps " << "Offset is " << d_next_tag_pos << std::endl;
        //  d_next_tag_pos += d_blockLength;
        // }
  	    // return noutput_items - size;	// else return partial result
      }

      /*
      Get tags
      */
      //std::cout << "\n\n\t" << nitems_written(0) << std::endl;
      while(d_next_tag_pos < nitems_written(0) + noutput_items) {
        add_item_tag(0, d_next_tag_pos, d_len_tag_key, d_packet_len_pmt);
        d_next_tag_pos += d_blockLength;
      }

      return noutput_items;
    }

  } /* namespace lets_test_some_stuff */
} /* namespace gr */
