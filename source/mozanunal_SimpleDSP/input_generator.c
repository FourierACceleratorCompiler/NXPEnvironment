
#include "../LPC55S69_Project.h"
#ifdef PROJ_mozanunal_SimpleDSP

#include "defines.h"
#include "self_contained_code.h"

COMPLEX *mozanunal_SimpleDSP_generate_inputs(int n) {
	COMPLEX *data = (COMPLEX *) malloc(n * sizeof(COMPLEX));

	for (int i = 0; i < n; i ++) {
		data[i].real = 2.0;
		data[i].imag = 1.0;
	}

	return data;
}

#endif
