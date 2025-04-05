
#include "teil/model/preprocessing/kernel.h"
#include "teil/model/svm/svc.h"
#include "teil/config.h"
#include <stdio.h>

int svc_predict_linear(svc_model_t model){
    feature_type (* svs_)[model.n_features] = model.weights;
    unsigned int d_rule = 0;
    int class = 0;

    for(int i=0; i < model.n_classes; i++){
        model.amounts[i] = 0;
        
    }


    for(int i = 0; i < model.n_intercepts; i++){
        model.decision_rules[i] = 0;
        for(int j = 0; j < model.n_features; j++){
            model.decision_rules[i] += (svs_[i][j] * model.sample[j]); 
        }
        
    }

    d_rule = 0;
    for(int i = 0; i < model.n_classes; i++){
        for(int j = i+1; j < model.n_classes; j++){
            if(model.decision_rules[d_rule] + model.intercepts[d_rule] > 0){
                model.amounts[i]++;
            }
            else{
                model.amounts[j]++;
            }
            d_rule++;
            
        }
        
    }

    for(int i=0; i<model.n_classes; i++){
        if(model.amounts[i] > model.amounts[class]){
            class = i;
        }
     
    }

    return class;

}

int svc_predict(svc_model_t model){
    unsigned int d_rule = 0, class = 0, i=0, j=0, k=0;
    
    if(model.kernel == KERNEL_LINEAR){
        return svc_predict_linear(model);
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

    feature_type (*weights)[model.n_support] = model.weights;

    //*

    for(i=0; i < model.n_classes; i++){
        model.amounts[i] = 0;
    }

    for(i=0; i < model.n_classes; i++){
        
        for(j=i+1; j < model.n_classes; j++){
            model.decision_rules[d_rule] = 0.0;
            for(k=model.ranges[j]; k<model.ranges[j+1]; k++){
                model.decision_rules[d_rule] += model.kernels[k] * weights[i][k];
            }

            for(k=model.ranges[i]; k<model.ranges[i+1]; k++){
                model.decision_rules[d_rule] += model.kernels[k] * weights[j-1][k];
            }

            if(model.decision_rules[d_rule] + model.intercepts[d_rule] > 0){
                model.amounts[i]++;
            }
            else{
                model.amounts[j]++;
            }

             d_rule++;

        }
    }

    for(i=0; i<model.n_classes; i++){
        class = (model.amounts[i] > model.amounts[class]) ? i : class;
    }


    return class;


}



output_type svc_predict_precomputed(svc_model_t model){

}