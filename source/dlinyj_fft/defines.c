#include "../LPC55S69_Project.h"

#ifdef PROJ_dlinyj_fft
// To be used with the defines in defines.h

int dlinyj_fft_sizes[] = { 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384 }; //, 32768 };

int log(int n) {
	int res = 0;
	while (n >>= 1) {
		res ++;
	}

	return res;
}

#endif
