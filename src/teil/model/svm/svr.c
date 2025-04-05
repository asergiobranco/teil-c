#include "teil/model/preprocessing/kernel.h"
#include "teil/model/svm/svr.h"
#include "teil/config.h"
#include <stdio.h>

double svr_predict(svr_model_t model){
    unsigned int i=0;
    
    if(model.kernel == KERNEL_LINEAR){
        return svr_predict_linear(model);
    }
    
    feature_type (*svs)[model.n_features] = model.support_vectors;
    switch(model.kernel){
        case KERNEL_POLY:
            kernel_polynomial(model.sample, svs , \
                model.n_support, model.n_features, model.kernels, \
                model.gamma, model.coef, model.degree);
            break;
        case KERNEL_RBF:
            kernel_rbf(model.sample, svs , \
                model.n_support, model.n_features, model.kernels, \
                model.gamma);
            break;
        

    }

    model.decision_rules = 0;

    for(i = 0; i < model.n_support; i++){
        model.decision_rules += (model.kernels[i] * model.weights[i]);
    }
    
    return model.decision_rules + model.intercepts;


}

double svr_predict_linear(svr_model_t model){

    model.decision_rules = 0;
    
    for(int j = 0; j < model.n_features; j++){
        model.decision_rules += (model.weights[j] * model.sample[j]); 
    }
        
    return model.decision_rules + model.intercepts;


}
