#ifndef __SVR__
#define __SVR__

#include "teil/model/preprocessing/kernel.h"
#include "teil/config.h"

typedef struct{
    unsigned int n_support;
    unsigned int n_features;
    enum KERNELS kernel;
    unsigned short int  degree;
    feature_type coef;
    feature_type gamma;
    feature_type * sample;
    feature_type * kernels;
    void * support_vectors;//[][];
    feature_type * weights;
    feature_type intercepts;
    feature_type decision_rules;

} svr_model_t;

double svr_predict(svr_model_t model);
double svr_predict_linear(svr_model_t model);



#endif