/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"

#ifdef PROJ_xbarin02_uFFT_2

#ifndef xbarin02_uFFT_2_H_
#define xbarin02_uFFT_2_H_
#include "self_contained_code.h"

extern void RUNFUN(int n);

_float_complex_ *xbarin02_uFFT_2_generate_inputs(int size);

#define SIZES 8
#define TEST_SIZES xbarin02_uFFT_2_sizes

extern int xbarin02_uFFT_2_sizes[];

#endif /* xbarin02_uFFT_2_H_ */

#endif
