
#include "../LPC55S69_Project.h"
#ifdef PROJ_tasimon_FFT

#include "defines.h"
#include "self_contained_code.h"

float *tasimon_FFT_generate_inputs(int n) {
	float *data = (float *) malloc(2 * n * sizeof(float));

	for (int i = 0; i < n; i ++) {
		data[i] = 2.0;
	}

	return data;
}

#endif
