#include "teil/config.h"

#ifndef __TEIL_GAUSSIANNB__
#define __TEIL_GAUSSIANNB__

typedef struct{
    unsigned int n_classes;
    unsigned int n_features;
    feature_type * sample;
    feature_type * class_prior;
    feature_type * joint_log_likelihood;
    void *pre_computed;
    void *var_;
    void *theta_;
    
} gaussian_nb_model_t;

int gaussiannb_predict(gaussian_nb_model_t model);

#endif 