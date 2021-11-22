
#include "../LPC55S69_Project.h"
#ifdef PROJ_xiahouzouxin_fft

#include "defines.h"
#include "self_contained_code.h"

COMPLEX *xiahouzouxin_fft_generate_inputs(int n) {
	COMPLEX *data = (COMPLEX *) malloc(n * sizeof(COMPLEX));

	for (int i = 0; i < n; i ++) {
		data[i].real = 1.0;
		data[i].imag = 2.0;
	}

	return data;
}

#endif
