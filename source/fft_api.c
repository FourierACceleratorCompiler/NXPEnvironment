/*
 * fft_api.c
 *
 *  Created on: 6 Aug 2021
 *
 *  Create an API wrapper that makes the interface simliar to
 *  that of the FFTA and FFTW to allow the same extraction-points
 *  to be used.
 *
 *  IMO this is the best interface in general for stateless
 *  FFT extraction.
 */

//#include "app.h"
#include "fft_api.h"
#include "fsl_powerquad.h"
#include "arm_math.h"
// Taken and adapted from the API documentation: https://www.nxp.com/docs/en/application-note/AN12383.pdf

// compute the largest integer y with x % y == 0 and x != y
// I think that's hard in the general case, so only support powers
// of two :)
static int approximate_sqaure_root_po2(int x) {
	int y = x / 2;

	// Assuming x is a power of two, all the factors
	// must be powers of two.
	while (x % y != 0)
		y = y / 2;

	return y;
}

static int intlog(int x) {
	int res = 0;
	while (x) {
		x >>= 1;
		res += 1;
	}

	return res;
}

void fft_api(complex_type *input, complex_type *output, int length) {
	q31_t in[length * 2];
	q31_t out[length * 2];
	for (int i = 0; i < 2 * length; i ++) {
		out[i]  = 0;
		in[i] = 0;
	}
	// Use power-quad for conversion as-per docs page 26
	pq_config_t pq_cfg;
	/*pq_cfg.inputAFormat = kPQ_Float;
	 pq_cfg.inputAPrescale = 0;
	 pq_cfg.inputBFormat = kPQ_32Bit;
	 pq_cfg.inputBPrescale = 0;
	 pq_cfg.tmpFormat = kPQ_32Bit;
	 pq_cfg.tmpPrescale = 0;
	 pq_cfg.outputFormat = kPQ_32Bit;
	 pq_cfg.outputPrescale = 0;
	 pq_cfg.tmpBase = (uint32_t *)0xE0000000;
	 pq_cfg.machineFormat = kPQ_Float;
	 PQ_SetConfig(POWERQUAD, &pq_cfg);*/
	// Seems broken for some reason?  Garr... The arm conversion is /super/ slow.
	// The hand-written one seems OK.

	// Make this into an approximately square matrix.
	//int col = approximate_sqaure_root_po2(length * 2);
	//PQ_MatrixScale(POWERQUAD, POWERQUAD_MAKE_MATRIX_LEN(2 * length, 1, 1), 1.0f / 32.0f, input, in);
	//PQ_MatrixScale(POWERQUAD, (16u << 8u) | 16u, 1 / (32.0f), input , in);
	//PQ_WaitDone(POWERQUAD);


	// using the powerquad would be faster, I just don't understand how to.
	//arm_float_to_q31((float *)input, in, length * 2);
	for (int i = 0; i < length * 2; i ++) {
		// Need to do this shift becuase PowerQuad only uses hte lower 27 bits.
		in[i] = (q31_t)(((float*)input)[i] * 2147483648) >> 5;
	}
	//for (int i = 0; i < length * 2; i ++)
		//printf("In %d (input was %.12f)\n", in[i], ((float *)input)[i]);


	// Setup the FFT  (From the API examples. powerquad_transform 32bit cfft)
    pq_cfg.inputAFormat   = kPQ_32Bit;
    pq_cfg.inputAPrescale = intlog(length);
    pq_cfg.inputBFormat   = kPQ_32Bit;
    pq_cfg.inputBPrescale = 0;
    pq_cfg.tmpFormat      = kPQ_32Bit;
    pq_cfg.tmpPrescale    = 0;
    pq_cfg.outputFormat   = kPQ_32Bit;
    pq_cfg.outputPrescale = 0;
    pq_cfg.tmpBase        = (uint32_t *)0xe0000000;
    pq_cfg.machineFormat  = kPQ_32Bit;
    PQ_SetConfig(POWERQUAD, &pq_cfg);

    PQ_TransformCFFT(POWERQUAD, length, in, out);
    //arm_cfft_instance_q31 inst;
    //arm_cfft_init_q31(&inst, length);
    //arm_cfft_q31(&inst, in, 0, 1);
    PQ_WaitDone(POWERQUAD);

    //for (int i = 0; i < length * 2; i ++) {
    	// undo the scaling.
    	// For some reason this was twice the 'nrmal' results,
    	// so also halve it.
    	//out[i] <<= 4;
    //}
;


	//for (int i = 0; i < length * 2; i ++)
		//printf("Out %d, %.13f\n", out[i] << 4, (float) (out[i] << 4) / 2.0f);


	// Now, convert output to floating-point.
	 /*pq_cfg.inputAFormat = kPQ_32Bit;
	 pq_cfg.inputAPrescale = 0;
	 pq_cfg.inputBFormat = kPQ_32Bit;
	 pq_cfg.inputBPrescale = 0;
	 pq_cfg.tmpFormat = kPQ_Float;
	 pq_cfg.tmpPrescale = 0;
	 pq_cfg.outputFormat = kPQ_Float;
	 pq_cfg.outputPrescale = 0;
	 pq_cfg.tmpBase = (uint32_t *)0xE0000000;
	 pq_cfg.machineFormat = kPQ_Float;
	 PQ_SetConfig(POWERQUAD, &pq_cfg);

	PQ_MatrixScale(POWERQUAD, POWERQUAD_MAKE_MATRIX_LEN(1, length * 2, 1), 16.0f,  out, output);
	PQ_WaitDone(POWERQUAD); */


	//arm_q31_to_float(out, (float *)output, length * 2);
	float *foutput = (float*) output;
	for (int i = 0; i < length * 2; i ++) {
		foutput[i] = ((float) (out[i] << 4)) / (2147483648.0);
	}

	//for (int i = 0; i < length; i ++)
			//printf ("Output %.12f\n", output[i].re);
}
