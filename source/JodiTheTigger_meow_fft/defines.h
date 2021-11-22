/*
 * defines.h
 *
 *  Created on: 16 Jun 2021
 *      Author: woodr
 */

#include "../LPC55S69_Project.h"
#ifdef PROJ_JodiTheTigger_meow_fft

#ifndef JODITHETIGGER_MEOW_FFT_DEFINES_H_
#define JODITHETIGGER_MEOW_FFT_DEFINES_H_
#include "context_code.h"

extern void RUNFUN(int n);
extern void RUNFUN(int n);

Meow_FFT_Complex *JodiTheTigger_meow_fft_generate_input(int size);

#define SIZES 6
#define TEST_SIZES JodiTheTigger_meow_fft_sizes

extern int JodiTheTigger_meow_fft_sizes[];

#endif /* JODITHETIGGER_MEOW_FFT_DEFINES_H_ */

#endif
