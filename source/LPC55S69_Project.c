/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    LPC55S69_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"
#include "fsl_powerquad.h"

#include "LPC55S69_Project.h"

#include "fft_api.h"
#include <stdlib.h>
/* TODO: insert other include files here. */

#define NUM 16

#ifdef PROJ_akw0088_fft
#include "akw0088_fft/defines.h"
#endif
#ifdef PROJ_cpuimage_cpuFFT
#include "cpuimage_cpuFFT/defines.h"
#endif
#ifdef PROJ_cpuimage_FFTResampler
#include "cpuimage_FFTResampler/defines.h"
// #include "cpuimage_FFTResampler/accelerated_ffta.cpp"
// #include "cpuimage_FFTResampler/wrapper.cpp"
#endif
#ifdef PROJ_cpuimage_StockhamFFT
#include "cpuimage_StockhamFFT/defines.h"
#endif
#ifdef PROJ_gregfjohnson_fft
#include "gregfjohnson_fft/defines.h"
#endif
#ifdef PROJ_JodiTheTigger_meow_fft
#include "JodiTheTigger_meow_fft/defines.h"
#endif
#ifdef PROJ_dlinyj_fft
#include "dlinyj_fft/defines.h"
#endif
#ifdef PROJ_jtfell_c_fft
#include "jtfell_c-fft/defines.h"
#endif
#ifdef PROJ_liscio_fft
#include "liscio_fft/defines.h"
#endif
#ifdef PROJ_liscio_fft_2
#include "liscio_fft_2/defines.h"
#endif
#ifdef PROJ_marton78_pffft
#include "marton78_pffft/defines.h"
#endif
#ifdef PROJ_mborgerding_kissfft
#include "mborgerding_kissfft/defines.h"
#endif
#ifdef PROJ_MiBench_MiBench
#include "MiBench_MiBench/defines.h"
#endif
#ifdef PROJ_mozanunal_SimpleDSP
#include "mozanunal_SimpleDSP/defines.h"
#endif
#ifdef PROJ_omnister_fftp
#include "omnister_fftp/defines.h"
#endif
#ifdef PROJ_tasimon_FFT
#include "tasimon_FFT/defines.h"
#endif
#ifdef PROJ_xbarin02_uFFT
#include "xbarin02_uFFT/defines.h"
#endif
#ifdef PROJ_xbarin02_uFFT_2
#include "xbarin02_uFFT_2/defines.h"
#endif
#ifdef PROJ_xiahouzouxin_fft
#include "xiahouzouxin_fft/defines.h"
#endif

#ifdef CRC
#include "crc32/crc32_main.h"
#endif

#ifdef FFT

/* TODO: insert other definitions and declarations here. */
complex_type *generate_test_inputs(int n) {
	complex_type *inps = (complex_type *) malloc(n * sizeof(complex_type));
	for (int i = 0; i < n; i ++) {
		inps[i].re = (float) rand() / (float) ((float)RAND_MAX * 1024.0f);
		inps[i].im = (float) rand() / (float) ((float)RAND_MAX * 1024.0f);
	}
	return inps;
}

/*
 * @brief   Application entry point.
 */
int main(void) {

	srand(0);

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    printf("Hello World\n");
    PQ_Init(POWERQUAD);

	for (int i = 0; i < BENCHMARK_TIMES; i ++) {
		for (int i = 0; i < SIZES; i ++) {
			int runsize = TEST_SIZES[i];
			printf("Starting runs for size %d:\n", runsize);
			RUNFUN(runsize);
			printf("Runs finished for size %d\n", runsize);
		}
	}

    /*complex_type *test_inputs = generate_test_inputs(NUM);
    complex_type test_outputs[NUM];
    printf("Pointer %p\n", test_inputs);

    for (int i = 0; i < NUM; i ++) {
    	printf("Inputs (%d): \n", i);
    	printf("%.12f, %.12f\n", test_inputs[i].re, test_inputs[i].im);
    }

    fft_api(test_inputs, test_outputs, NUM);

	printf("Outputs:\n");
    for (int i = 0; i < NUM; i ++) {
    	printf("%.12f, %.12f\n", test_outputs[i].re, test_outputs[i].im);
    }*/

    return 0 ;
}

#endif
