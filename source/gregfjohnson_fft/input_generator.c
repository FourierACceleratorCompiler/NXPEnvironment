
#include "../LPC55S69_Project.h"
#ifdef PROJ_gregfjohnson_fft

#include "defines.h"
#include "self_contained_code.h"

_complex_double_ *gregfjohnson_fft_generate_inputs(int n) {
	_complex_double_ *data = (_complex_double_ *) malloc(n * sizeof(_complex_double_));

	for (int i = 0; i < n; i ++) {
		data[i].re = 2.0;
		data[i].im = 1.0;
	}

	return data;
}

#endif
