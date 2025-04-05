
#include <math.h>
#include "teil/config.h"
#include "teil/model/preprocessing/kernel.h"
/*
feature_type * kernel_linear(feature_type * sample, feature_type * kernel_vectors , unsigned int n_kernel, unsigned int n_features, feature_type * kernels){
    int i = 0, j=0;

    for(i=0; i<n_kernel; i++){
        kernels[i] = 0;
        for(j=0; j<n_features; j++){
            kernels[i] += kernel_vectors[i][j] * sample[j];
        }
    }

    return kernels;
}
*/

feature_type * kernel_polynomial(feature_type * sample, void * kernel_vectors , \
            unsigned int n_kernel, unsigned int n_features, feature_type * kernels, feature_type gamma, feature_type coef, unsigned int degree){
    
    int i = 0, j=0;
    feature_type (*svs)[n_features] = kernel_vectors;
    for(i=0; i<n_kernel; i++){
        kernels[i] = 0;
        for(j=0; j<n_features; j++){
            kernels[i] += svs[i][j] * sample[j];
        }
    }

    for(int i=0; i<n_kernel; i++){
        kernels[i] = (gamma * kernels[i] + coef);
        kernels[i] = pow(kernels[i], degree);
    }

    return kernels;
}

//*
feature_type * kernel_rbf(feature_type * sample, void * kernel_vectors , \
            unsigned int n_kernel, unsigned int n_features, feature_type * kernels, feature_type gamma){
    int i = 0, j=0;
    feature_type (*svs)[n_features] = kernel_vectors;
    for(i=0; i<n_kernel; i++){
        kernels[i] = 0;
        for(j=0; j<n_features; j++){
            kernels[i] += (svs[i][j] - sample[j]) * (svs[i][j] - sample[j]);
        }
        kernels[i] = exp(-1* gamma * kernels[i]);
    }

    return kernels;
}
//*/

