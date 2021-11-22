
#ifdef PROJ_liscio_fft_2

#include "../clib/synthesizer.h"
#include "self_contained_code.h"
#include <stdio.h>
#include "defines.h"
#include <time.h>


void run_original(int n) {

_complex_double_ *x = liscio_fft_2_generate_inputs(n);

cycle_stats_t S;
CYCLES_INIT(S);
CYCLES_START(S);
_complex_double_ *returnv;
for (int i = 0; i < TIMES; i ++) {
	returnv = FFT_wrapper(x, n);
	free(returnv); // Could be done outside the loop, but the FFTA is very low on memory, so best done here.
}

CYCLES_STOP(S);
//printf("Done\n");
//clock_t end = clock();
printf("Time: %.12f\n", (double) (S._cycles) / CYCLES_PER_SECOND);
printf("AccTime: %.12f\n", (double) 0);

free(x);
}

#endif
