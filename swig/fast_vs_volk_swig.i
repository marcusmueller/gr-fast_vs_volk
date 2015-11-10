/* -*- c++ -*- */

#define FAST_VS_VOLK_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "fast_vs_volk_swig_doc.i"

%{
#include "fast_vs_volk/comparison.h"
%}


%include "fast_vs_volk/comparison.h"
