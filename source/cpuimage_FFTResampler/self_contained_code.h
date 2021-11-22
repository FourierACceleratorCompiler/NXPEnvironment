#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_FFTResampler

#ifndef SELF_CONTAINED_H
#define SELF_CONTAINED_H

#ifdef USE_DOUBLE_TYPE
#define stb_real_t double
#else
#define stb_real_t float
#endif

typedef struct  {
		    stb_real_t real;
		    stb_real_t imag;
		} cmplx;

void STB_FFT(cmplx* input, cmplx* output, int n);

#endif

#endif
