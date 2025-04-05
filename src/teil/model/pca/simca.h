#ifndef __SIMCA__
#define __SIMCA__ 

#include <stdbool.h> 

typedef struct{
    unsigned int n_classes;
    unsigned int n_train;
    unsigned int den; // (n_features -n_components) * (n_train - 1 - n_components)
    double squared_train; // np.sum(X**2)
    double * feature_sum; //[np.sum(X[::,i]) for i in range(N_FEATURES)]
    pca_model_t * pca_models; //pca for each class 
    double * classes_f_crit;
    bool * classification;
} simca_model_t;


// np.sum(2*new_sample * feature_sum) + n_train*np.sum(new_sample**2) + squared_train
#endif 