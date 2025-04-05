#ifndef __MLPR__
#define __MLPR__

#include "teil/config.h"
#include "teil/model/neural_network/activation.h"
#include "teil/model/neural_network/neural_utils.h"


typedef struct{
    unsigned int n_features;
    unsigned int n_layers;
    feature_type *sample;
    mlp_hidden_layer_t ** hidden_layers;
} mlpr_model_t;

double  mlpr_predict(mlpr_model_t model);

#endif 