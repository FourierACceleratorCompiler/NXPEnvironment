#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_FFTResampler
#include "defines.h"

cmplx *cpuimage_FFTResampler_generate_input(int size) {
	cmplx *data = (cmplx *) malloc(size * sizeof(cmplx));

	for (int i = 0; i < size; i ++) {
		data[i].real = 1.0;
		data[i].imag = 2.0;
	}

	return data;
}

#endif
