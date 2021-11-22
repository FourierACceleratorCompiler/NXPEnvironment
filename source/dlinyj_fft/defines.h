/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"

#ifdef PROJ_dlinyj_fft

#ifndef dlinyj_fft_H_
#define dlinyj_fft_H_
#include "self_contained_code.h"
#include "../LPC55S69_Project.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

float *dlinyj_fft_generate_inputs(int size);

#define SIZES 8
#define TEST_SIZES dlinyj_fft_sizes

extern int dlinyj_fft_sizes[];
int log(int n);

#endif /* dlinyj_fft_H_ */

#endif
