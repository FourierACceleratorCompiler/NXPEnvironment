typedef struct complex_type {
	float re;
	float im;
} complex_type;

void fft_api(complex_type *input, complex_type *output, int length);
