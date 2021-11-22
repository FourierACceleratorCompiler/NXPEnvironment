/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"

#ifdef PROJ_jtfell_c_fft

#ifndef JTFELL_C_FFT_H_
#define JTFELL_C_FFT_H_
#include "self_contained_code.h"
#include "../LPC55S69_Project.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

jcomplex *jtfell_c_fft_generate_input(int size);

#define SIZES 8
#define TEST_SIZES jtfell_c_fft_sizes

extern int jtfell_c_fft_sizes[];

#endif /* JTFELL_C_FFT_H_ */

#endif
