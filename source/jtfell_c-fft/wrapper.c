#include "../LPC55S69_Project.h"

#ifdef PROJ_jtfell_c_fft

#include "../clib/synthesizer.h"
#include "self_contained_code.h"
#include <stdio.h>
#include "defines.h"
#include <time.h>

void run_original(int n) {

jcomplex *x = jtfell_c_fft_generate_inputs(n);
clock_t begin = clock();
jcomplex *returnv;
for (int i = 0; i < TIMES; i ++) {
	returnv = DFT_naive(x, n);
	free(returnv);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) 0);

free(x);
}

#endif
