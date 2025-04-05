#include "teil/config.h"
#include "teil/preprocessing/scaler.h"

feature_type * std_scaler_transform(std_scaler_t model){

    for(int i = 0; i < model.n_features; i++){
        model.sample[i] = (model.sample[i] - model.mean_x[i]) / model.std_x[i];
    }

    return model.sample;

}


feature_type * std_scaler_inverse(std_scaler_t model){

    for(int i = 0; i < model.n_features; i++){
        model.sample[i] = (model.sample[i] * model.std_x[i]) + model.mean_x[i];
    }

    return model.sample;

}

feature_type * minmax_transform(min_max_scaler_t model){

    for(int i = 0; i < model.n_features; i++){
        model.sample[i] = (model.sample[i] - model.min[i]) / (model.max[i] - model.min[i]);
    }

    return model.sample;

}

feature_type * minmax_inverse(min_max_scaler_t model){

    for(int i = 0; i < model.n_features; i++){
        model.sample[i] = (model.sample[i]  * (model.max[i] - model.min[i])) + model.min[i];
    }

    return model.sample;

}


feature_type * normalizer(normalizer_scaler_t model){
    
    switch(type){
        case NORMALIZE_L1:
            model.norm = 0;
            for(int i = 0; i < model.n_features; i++){
                if(model.sample[i] < 0){
                    model.norm += (-1*model.sample[i]);
                }
                else{
                    model.norm += (model.sample[i]);
                }
            }
            break;
        case NORMALIZE_L2:
            model.norm = 0;
            for(int i = 0; i < model.n_features; i++){
                model.norm += (model.sample[i] * model.sample[i]);
            }
            break;
        case NORMALIZE_MAX:
            model.norm = model.sample[i];
            feature_type aux = 0;
            for(int i = 0; i < model.n_features; i++){
                if(model.sample[i] < 0){
                    aux = (-1*model.sample[i]);
                }
                else{
                    aux = (model.sample[i]);
                }

                if(aux > model.norm){model.norm = aux;}
            }
            break;
        
    }

    if(model.norm = 0){
        return model.sample;
    }

    for(int i = 0; i < model.n_features; i++){
        model.sample[i] /= model.norm;
    }

    return model.sample;
}