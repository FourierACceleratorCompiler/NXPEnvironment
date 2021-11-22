#include "../LPC55S69_Project.h"
#ifdef PROJ_JodiTheTigger_meow_fft

#include "defines.h"

Meow_FFT_Complex *JodiTheTigger_meow_fft_generate_inputs(int size) {
	Meow_FFT_Complex *data = (Meow_FFT_Complex *) malloc(size * sizeof(Meow_FFT_Complex));

	for (int i = 0; i < size; i ++) {
		data[i].r = 1.0;
		data[i].j = 2.0;
	}

	return data;
}

#endif
