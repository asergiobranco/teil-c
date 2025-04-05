#ifndef __KERNEL__
#define __KERNEL__ 

#include "teil/config.h"

enum KERNELS{
    KERNEL_LINEAR,
    KERNEL_POLY,
    KERNEL_RBF,
    KERNEL_TAHN
};

feature_type * kernel_polynomial(feature_type * sample, void * kernel_vectors , \
            unsigned int n_kernel, unsigned int n_features, feature_type * kernels, feature_type gamma, feature_type coef, unsigned int degree);

feature_type * kernel_rbf(feature_type * sample, void * kernel_vectors , \
            unsigned int n_kernel, unsigned int n_features, feature_type * kernels, feature_type gamma);
            
#endif
