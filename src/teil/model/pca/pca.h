#ifndef __PCA__
#define __PCA__

#include "teil/config.h"

typedef struct{
    feature_type * sample;
    unsigned int n_features;
    unsigned int n_pcs;
    void * correlation_matrix;//[N_FEATURES][N_FEATURES]; //correlation matrix A
    void * U;//[N_FEATURES][N_FEATURES];
    //Principal components * -1 
    void * v; //[N_FEATURES][N_FEATURES];
    void * singular_values;// [N_FEATURES];
    void * explained_variance_ratio;//[N_FEATURES];
    double * scores; //N_PCS 
    double * inverse; //N_FEATURES
    double * Av; //N_FEATURES
    double *error; //N_FEATURES
} pca_model_t;

void pca_transform(pca_model_t model);
void pca_inverse(pca_model_t model);
void pca_error(pca_model_t model);
void pca_fit(pca_model_t model);

#endif