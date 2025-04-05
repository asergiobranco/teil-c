#include "teil/model/neural_network/activation.h"
#include "teil/model/neural_network/neural_utils.h"
#include <math.h>

void propagation(mlp_hidden_layer_t * layer, double * prev_layer_values, unsigned int prev_layer_size){

    
    double (*weights)[layer->n_neurons] = layer->weights;
    
    for(int i = 0; i < layer->n_neurons; i++){
        layer->neurons[i] = layer->bias[i];
        for(int j = 0; j < prev_layer_size; j++){
            layer->neurons[i] += (weights[j][i] * prev_layer_values[j]);
        }

        
        switch(layer->activation){
            case ACTIVATION_RELU:
                layer->neurons[i] = relu(layer->neurons[i]);
                break;
            case ACTIVATION_LEAKY_RELU:
                layer->neurons[i] = leaky_relu(layer->neurons[i]);
                break;
            case ACTIVATION_SIGMOID:
                layer->neurons[i] = logistic(layer->neurons[i]);
                break;
            case ACTIVATION_SWISH:
                layer->neurons[i] = layer->neurons[i]*logistic(layer->neurons[i]);
                break;
            case ACTIVATION_TANH:
                layer->neurons[i] = tanh(layer->neurons[i]);
                break;
            case ACTIVATION_LOGISTIC:
                layer->neurons[i] = logistic(layer->neurons[i]);
                break;
            case ACTIVATION_IDENTITY:
                break;
        }
    }
}