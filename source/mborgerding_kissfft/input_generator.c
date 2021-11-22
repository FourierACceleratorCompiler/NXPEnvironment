
#include "../LPC55S69_Project.h"
#ifdef PROJ_mborgerding_kissfft

#include "defines.h"
#include "self_contained_code.h"

kiss_fft_cpx *mborgerding_kissfft_generate_inputs(int n) {
	kiss_fft_cpx *data = (kiss_fft_cpx *) malloc(n * sizeof(kiss_fft_cpx));

	for (int i = 0; i < n; i ++) {
		data[i].r = 1.0;
		data[i].i = 2.0;
	}

	return data;
}

#endif
