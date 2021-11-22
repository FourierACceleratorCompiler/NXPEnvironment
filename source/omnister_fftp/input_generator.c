#include "../LPC55S69_Project.h"
#ifdef PROJ_omnister_fftp

#include "defines.h"

COMPLEX *omnister_fftp_generate_inputs(int size) {
	COMPLEX *data = (COMPLEX *) malloc(size * sizeof(COMPLEX));

	for (int i = 0; i < size; i ++) {
		data[i].re = 1.0;
		data[i].im = 2.0;
	}

	return data;
}

#endif
