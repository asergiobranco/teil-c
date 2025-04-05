#ifndef __MLP_UTILS__
#define __MLP_UTILS__

#include "teil/model/neural_network/activation.h"
#include "teil/model/neural_network/neural_utils.h"

typedef struct{
    void * weights;
    double * bias;
    double * neurons;
    unsigned int n_neurons;
    unsigned int activation;
} mlp_hidden_layer_t;


void propagation(mlp_hidden_layer_t * layer, double * prev_layer_values, unsigned int prev_layer_size);


#endif