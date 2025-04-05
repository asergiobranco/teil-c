#include "teil/model/neural_network/mlpc.h"
#include "teil/model/neural_network/neural_utils.h"
#include "teil/model/neural_network/activation.h"
#include "teil/config.h"
#include <math.h>
#include <stdio.h>

output_type mlpc_predict(mlpc_model_t model){

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
    softmax(prev->neurons, prev->n_neurons);

    if(prev->n_neurons == 1){
        return (prev->neurons[0] > 0.5) ? 1 : 0;
    }
    double max = prev->neurons[0];
    output_type cls = 0;
    for(int i = 1; i < prev->n_neurons; i++){
        if(prev->neurons[i] > max){
            cls = i;
            max = prev->neurons[i];
        }
    }
    //*/

    return cls;
}