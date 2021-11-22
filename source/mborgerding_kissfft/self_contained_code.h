#include "../LPC55S69_Project.h"

#ifdef PROJ_mborgerding_kissfft


#ifndef mborgerding_kissfft_SELF_CONTAINED_CODE_H_
#define mborgerding_kissfft_SELF_CONTAINED_CODE_H_

#   define kiss_fft_scalar float
typedef struct {
    kiss_fft_scalar r;
    kiss_fft_scalar i;
}kiss_fft_cpx;


#endif
#endif
