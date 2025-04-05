#include "teil/config.h"
#include "teil/model/bayes/gaussiannb.h"

int gaussiannb_predict(gaussian_nb_model_t model){
   
    feature_type n_ij = 0;
    feature_type aux = 0;
    feature_type max = 0;
    int out = 0;
    
    feature_type (* theta_)[model.n_features] = model.theta_;
    feature_type (* var_)[model.n_features] = model.var_;
    feature_type (*pre_computed_)[model.n_features] = model.pre_computed;

    for(int i = 0; i < model.n_classes; i++){
        aux = 0;
        for(int j = 0; j < model.n_features; j++){
            n_ij = pre_computed_[i][j];
            aux += ((model.sample[j] - theta_[i][j]) * (model.sample[j] - theta_[i][j])) / var_[i][j];
        }

        n_ij -= 0.5*aux;
        model.joint_log_likelihood[i] = (model.class_prior[i] + n_ij);
    }

    max = model.joint_log_likelihood[out];

    for(int i = 1; i < model.n_classes; i++){
        if(model.joint_log_likelihood[i] > max){
            max = model.joint_log_likelihood[i];
            out = i;
        }
    }

    return out;

}

