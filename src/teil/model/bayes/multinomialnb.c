#include "teil/config.h"
#include "teil/model/bayes/multinomialnb.h"

output_type multinomialnb_predict(multinomialnb_model_t model){
    
    feature_type max = 0;
    output_type out = 0;

    feature_type (*feature_log_prob_)[model.n_features] = model.feature_log_prob_;

    for(int i = 0; i < model.n_classes; i++){
        model.joint_log_likelihood[i] = 0;
        
        for(int j = 0; j < model.n_features; j++){
            model.joint_log_likelihood[i] += (model.sample[j] * feature_log_prob_[i][j])
        }

        model.joint_log_likelihood[i] += model.class_log_prior_[i];

    }

    max = model.joint_log_likelihood[out];

    for(output_type i = out; i < model.n_classes; i++){
        if(model.joint_log_likelihood[i] > max){
            max = model.joint_log_likelihood[i];
            out = i;
        }
    }

    return out;

}