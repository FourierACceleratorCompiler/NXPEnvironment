/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"
#ifdef PROJ_akw0088_fft

#ifndef akw0088_fft_DEFINES_H_
#define akw0088_fft_DEFINES_H_
#include "self_contained_code.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

j_complex_t *akw0088_fft_generate_input(int size);

#define SIZES 8
#define TEST_SIZES akw0088_fft_sizes

extern int akw0088_fft_sizes[];

#endif /* akw0088_fft_DEFINES_H_ */

#endif
