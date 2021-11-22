/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"

#ifdef PROJ_tasimon_FFT

#ifndef tasimon_FFT_H_
#define tasimon_FFT_H_
#include "self_contained_code.h"

extern void RUNFUN(int n);

float *tasimon_FFT_generate_inputs(int size);

#define SIZES 1
#define TEST_SIZES tasimon_FFT_sizes

extern int tasimon_FFT_sizes[];

#endif /* tasimon_FFT_H_ */

#endif
