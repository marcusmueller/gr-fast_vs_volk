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


#ifndef INCLUDED_FAST_VS_VOLK_COMPARISON_H
#define INCLUDED_FAST_VS_VOLK_COMPARISON_H

#include <fast_vs_volk/api.h>
#include <gnuradio/io_signature.h>

namespace gr {
  namespace fast_vs_volk {

    /*!
     * \brief Allocate space and run comparison
     *
     */
    class FAST_VS_VOLK_API comparison
    {
    public:
      comparison(size_t num_of_complexes = (1<<20));
      void run_fast_atan2(float *target);
      void run_volk_atan2(float *target);
      void run_complex_arg(float *target);
      void run_libc_atan2(float *target);

      ~comparison();
    private:
      gr_complex *d_buffer;
      size_t d_len;
    };

  } // namespace fast_vs_volk
} // namespace gr

#endif /* INCLUDED_FAST_VS_VOLK_COMPARISON_H */

