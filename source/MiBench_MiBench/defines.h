/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */
#include "../LPC55S69_Project.h"
#ifdef PROJ_MiBench_MiBench

#ifndef MiBench_MiBench_DEFINES_H_
#define MiBench_MiBench_DEFINES_H_
#include "self_contained_code.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

float *MiBench_MiBench_generate_input(int size);

#define SIZES 6
#define TEST_SIZES MiBench_MiBench_sizes

extern int MiBench_MiBench_sizes[];

#endif /* MiBench_MiBench_DEFINES_H_ */

#endif
