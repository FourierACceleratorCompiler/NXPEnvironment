#include "../LPC55S69_Project.h"
#ifdef PROJ_liscio_fft

#include "defines.h"
#include "self_contained_code.h"

_complex_double_ *liscio_fft_generate_inputs(int size) {
	_complex_double_ *data = (_complex_double_ *) malloc(size * sizeof(_complex_double_));

	for (int i = 0; i < size; i ++) {
		data[i].re = 1.0;
		data[i].im = 2.0;
	}

	return data;
}

#endif
