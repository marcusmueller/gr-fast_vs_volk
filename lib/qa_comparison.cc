/* -*- c++ -*- */
/* 
 * Copyright 2015 Marcus Müller.
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
 * Boston, MA 02710-1301, USA.
 */


#include <gnuradio/attributes.h>
#include <cppunit/TestAssert.h>
#include "qa_comparison.h"
#include <fast_vs_volk/comparison.h>
#include <boost/timer/timer.hpp>
#include <volk/volk.h>

#define NUM ((1<<25))
namespace gr {
  namespace fast_vs_volk {

    void
    qa_comparison::t1_fast()
    {
       std::cout <<std::flush<< "fast: ";
       // set up comparison
       comparison cmp(NUM);
       float *outbuf = (float*) volk_malloc(sizeof(gr_complex)*(NUM), volk_get_alignment());
       {
           boost::timer::auto_cpu_timer t;
           cmp.run_fast_atan2(outbuf);
       }
       std::cout <<std::endl<<std::flush;
    }

    void
    qa_comparison::t2_volk()
    {
       std::cout <<std::flush<< "volk: ";
       // set up comparison
       comparison cmp(NUM);
       float *outbuf = (float*) volk_malloc(sizeof(gr_complex)*(NUM), volk_get_alignment());
       {
           boost::timer::auto_cpu_timer t;
           cmp.run_volk_atan2(outbuf);
       }
       std::cout <<std::endl<<std::flush;
    }
    void
    qa_comparison::t3_libc()
    {
       std::cout <<std::flush<< "libc: ";
       // set up comparison
       comparison cmp(NUM);
       float *outbuf = (float*) volk_malloc(sizeof(gr_complex)*(NUM), volk_get_alignment());
       {
           boost::timer::auto_cpu_timer t;
           cmp.run_libc_atan2(outbuf);
       }
       std::cout <<std::endl<<std::flush;
    }
    void
    qa_comparison::t4_arg()
    {
       std::cout <<std::flush<< "c++ complex arg: ";
       // set up comparison
       comparison cmp(NUM);
       float *outbuf = (float*) volk_malloc(sizeof(gr_complex)*(NUM), volk_get_alignment());
       {
           boost::timer::auto_cpu_timer t;
           cmp.run_complex_arg(outbuf);
       }
       std::cout <<std::endl<<std::flush;
    }


  } /* namespace fast_vs_volk */
} /* namespace gr */
#undef NUM
