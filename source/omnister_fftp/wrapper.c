#include "../LPC55S69_Project.h"

#ifdef PROJ_omnister_fftp

#include "../clib/synthesizer.h"
#include <stdio.h>
#include "defines.h"
#include <time.h>


void run_original(int n) {

	COMPLEX *array = omnister_fftp_generate_inputs(n);

	clock_t begin = clock();
	for (int i = 0; i < TIMES; i ++) {
		array = fft_1d(array, n);
	}
	clock_t end = clock();
	printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
	printf("AccTime: %.12f\n", (double) 0 / CLOCKS_PER_SEC);

	free(array);
}

#endif
