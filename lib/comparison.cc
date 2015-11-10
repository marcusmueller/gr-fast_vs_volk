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
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include <fast_vs_volk/comparison.h>
#include <volk/volk.h>
#include <gnuradio/math.h>
#include <gnuradio/random.h>
#include <math.h>

namespace gr {
  namespace fast_vs_volk {

    comparison::comparison(size_t num_of_complexes):
        d_len(num_of_complexes)
    {
        d_buffer = (gr_complex*)volk_malloc(sizeof(gr_complex)*num_of_complexes, volk_get_alignment());
        //fill buffer with random data 
        gr::random rng;
        for(size_t idx = 0; idx < d_len; idx++) {
            d_buffer[idx] =  rng.rayleigh_complex();
        }
        //make half of the values small-angled
        for(size_t idx = 0; idx < d_len; idx += 2) {
            d_buffer[idx].real() = d_buffer[idx].imag() * (1.0 + 0.003 * rng.ran1()); 
        }

    }
    void
    comparison::run_fast_atan2(float *target) {
        for(size_t idx = 0; idx < d_len; idx++)
        	target[idx] = gr::fast_atan2f(d_buffer[idx]);
    }

    void
    comparison::run_volk_atan2(float *target) {
       volk_32fc_s32f_atan2_32f(target, d_buffer, 1.0f , d_len);
    }
    void
    comparison::run_libc_atan2(float *target) {
        float curr, next;
        for(float *f_buff = (float*) d_buffer; f_buff < ((float*)d_buffer) + 2*d_len; f_buff++) {
            curr = *f_buff;
            f_buff++;
            next = *f_buff;
        	*target = atan2f(curr, next);
            target++;
        }
    }
    void
    comparison::run_complex_arg(float *target) {
        for(size_t idx = 0; idx < d_len; idx++)
        	target[idx] = std::arg(d_buffer[idx]);
    }

    comparison::~comparison()
    {
    }

  } /* namespace fast_vs_volk */
} /* namespace gr */

