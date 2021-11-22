#include "../LPC55S69_Project.h"

#ifdef PROJ_marton78_pffft

#define SETUP_STRUCT               PFFFT_Setup

#ifndef marton78_pffft_SELF_CONTAINED_CODE_H_
#define marton78_pffft_SELF_CONTAINED_CODE_H_

// Just pull out the defs required to make this run on the board.

typedef float vsfscalar;

typedef vsfscalar v4sf;

// See notes - this is to re-sugar the enum types without
// having to implement them in FACC>
// This is basically emulating what the compiler would do
// as it deconstructs the program.
typedef struct {
	int N;
	int Ncvec;
	int *ifac;
	int transform;
	v4sf *data;
	float *e;
	float *twiddle;
} PFFFT_Setup_Desugar;

typedef enum { PFFFT_FORWARD, PFFFT_BACKWARD } pffft_direction_t;

/* type of transform */
typedef enum { PFFFT_REAL, PFFFT_COMPLEX } pffft_transform_t;

struct SETUP_STRUCT {
  int     N;
  int     Ncvec;  /* nb of complex simd vectors (N/4 if PFFFT_COMPLEX, N/8 if PFFFT_REAL) */
  int ifac[15];
  pffft_transform_t transform;
  v4sf *data;     /* allocated room for twiddle coefs */
  float *e;       /* points into 'data', N/4*3 elements */
  float *twiddle; /* points into 'data', N/4 elements */
};

#endif
#endif
