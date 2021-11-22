/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_cpuFFT

#ifndef cpuimage_cpuFFT_DEFINES_H_
#define cpuimage_cpuFFT_DEFINES_H_
#include "self_contained_code.h"
#include "../LPC55S69_Project.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

cmplx *cpuimage_cpuFFT_generate_input(int size);

#define SIZES 8
#define TEST_SIZES cpuimage_cpuFFT_sizes

extern int cpuimage_cpuFFT_sizes[];

#endif /* cpuimage_cpuFFT_DEFINES_H_ */

#endif
