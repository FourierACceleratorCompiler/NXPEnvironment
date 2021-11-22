/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_StockhamFFT

#ifndef cpuimage_StockhamFFT_DEFINES_H_
#define cpuimage_StockhamFFT_DEFINES_H_
#include "self_contained_code.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

complex_t *cpuimage_StockhamFFT_generate_input(int size);

#define SIZES 8
#define TEST_SIZES cpuimage_StockhamFFT_sizes

extern int cpuimage_StockhamFFT_sizes[];

#endif /* cpuimage_StockhamFFT_DEFINES_H_ */

#endif
