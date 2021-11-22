#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_StockhamFFT
#include "defines.h"

complex_t *cpuimage_StockhamFFT_generate_input(int size) {
	complex_t *data = (complex_t *) malloc(size * sizeof(complex_t));

	for (int i = 0; i < size; i ++) {
		data[i].real = 1.0;
		data[i].imag = 2.0;
	}

	return data;
}

#endif
