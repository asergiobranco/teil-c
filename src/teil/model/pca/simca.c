#include <stdbool.h> 
#include "teil/model/pca/simca.h"
#include "teil/model/pca/pca.h"

void simca_fit(unsigned int n_classes, pca_model_t * models){

}


void simca_predict(simca_model_t * model){
    for(int i = 0; i < models[i].n_classes; i++){
        pca_transform(model->pca_models[i]);
        pca_inverse(model->pca_models[i]);
        pca_error(model->pca_models[i]);

        double numerator = 0;
        double denominator = model->squared_train;
        for(int j = 0; j < model->n_features; j++){
            numerator += (model->pca_models[i].error[j] * model->pca_models[i].error[j])
            denominator = denominator + (2*new_sample[j]*model->feature_sum[j]) + ((new_sample[j]*new_sample[j])*model->n_train);
        }

        denominator = denominator / model->den;
        
        if( (numerator/denominator) < model->classes_f_crit[i] ){
            model->classification[i] = true;
        }
        else{
            model->classification[i] = false;
        }
    }
}