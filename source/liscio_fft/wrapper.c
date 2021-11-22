#include "../LPC55S69_Project.h"

#ifdef PROJ_liscio_fft

#include "../clib/synthesizer.h"
#include "self_contained_code.h"
#include <stdio.h>
#include "defines.h"
#include <time.h>

void run_original(int n) {

_complex_double_ *x = liscio_fft_generate_inputs(n);
clock_t begin = clock();
_complex_double_ *returnv;
for (int i = 0; i < TIMES; i ++) {
	returnv = FFT_wrapper(x, n);
	free(returnv); // Could be done outside the loop, but the FFTA is very low on memory, so best done here.
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) 0);

free(x);
}

#endif
