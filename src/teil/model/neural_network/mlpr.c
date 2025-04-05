#include "teil/model/neural_network/activation.h"
#include "teil/model/neural_network/neural_utils.h"
#include "teil/model/neural_network/mlpr.h"

double mlpr_predict(mlpr_model_t model){

    mlp_hidden_layer_t *prev, *layer;
    //**

    layer = model.hidden_layers[0];

    propagation(layer, model.sample, model.n_features);
    int l = 1;

    for(l = 1; l < model.n_layers; l++){
        layer = model.hidden_layers[l];
        prev = model.hidden_layers[l-1];
        propagation(layer, prev->neurons, prev->n_neurons);
    }

    prev = model.hidden_layers[l-1];
    //softmax(prev->neurons, prev->n_neurons);

    return prev->neurons[0];

}