#ifndef __MLPC__
#define __MLPC__

#include "teil/config.h"
#include "teil/model/neural_network/neural_utils.h"

typedef struct{
    unsigned int n_features;
    unsigned int n_classes;
    unsigned int n_layers;
    feature_type *sample;
    mlp_hidden_layer_t ** hidden_layers;
} mlpc_model_t;

output_type mlpc_predict(mlpc_model_t model);

#endif 