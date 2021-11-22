
#include "../LPC55S69_Project.h"
#ifdef PROJ_marton78_pffft

#include "defines.h"
#include "self_contained_code.h"


float *marton78_pffft_generate_inputs(int n) {
	float *data = (float *) malloc(2 * n * sizeof(float));

	for (int i = 0; i < 2 * n; i ++) {
		data[i] = 1.0;
	}

	return data;
}

#endif
