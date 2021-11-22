/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"

#ifdef PROJ_liscio_fft

#ifndef liscio_fft_H_
#define liscio_fft_H_
#include "self_contained_code.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

_complex_double_ *liscio_fft_generate_input(int size);

#define SIZES 6
#define TEST_SIZES liscio_fft_sizes

extern int liscio_fft_sizes[];

#endif /* liscio_fft_H_ */

#endif
