#ifndef __SVC__
#define __SVC__

#include "teil/model/preprocessing/kernel.h"
#include "teil/config.h"

typedef struct{
    unsigned int n_support;
    unsigned int n_intercepts;
    unsigned int n_classes;
    unsigned int n_features;
    unsigned int * amounts;
    unsigned int * ranges;
    enum KERNELS kernel;
    unsigned short int  degree;
    feature_type coef;
    feature_type gamma;
    feature_type * sample;
    feature_type * kernels;
    void * support_vectors;//[][];
    void * weights;
    feature_type * intercepts;
    feature_type * decision_rules;

} svc_model_t;

int svc_predict(svc_model_t model);
int svc_predict_linear(svc_model_t model);



#endif