#include "../LPC55S69_Project.h"
#ifdef PROJ_jtfell_c_fft

#include "defines.h"

jcomplex *jtfell_c_fft_generate_inputs(int size) {
	jcomplex *data = (jcomplex *) malloc(size * sizeof(jcomplex));

	for (int i = 0; i < size; i ++) {
		data[i].re = 1.0;
		data[i].im = 2.0;
	}

	return data;
}

#endif
