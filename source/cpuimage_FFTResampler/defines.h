/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_FFTResampler

#ifndef CPUIMAGE_FFTRESAMPLER_DEFINES_H_
#define CPUIMAGE_FFTRESAMPLER_DEFINES_H_
#include "self_contained_code.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

cmplx *cpuimage_FFTResampler_generate_input(int size);

#define SIZES 6
#define TEST_SIZES cpuimage_FFTResampler_sizes

extern int cpuimage_FFTResampler_sizes[];

#endif /* CPUIMAGE_FFTRESAMPLER_DEFINES_H_ */

#endif
