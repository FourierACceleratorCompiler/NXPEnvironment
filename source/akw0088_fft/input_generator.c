#include "../LPC55S69_Project.h"
#ifdef PROJ_akw0088_fft
#include "defines.h"

j_complex_t *akw0088_fft_generate_input(int size) {
	j_complex_t *data = (j_complex_t *) malloc(size * sizeof(j_complex_t));

	for (int i = 0; i < size; i ++) {
		data[i].real = 1.0;
		data[i].imag = 2.0;
	}

	return data;
}

#endif
