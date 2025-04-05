#include "teil/model/neural_network/activation.h"
#include <math.h>

double identity(double neuron){
    return neuron;
}

double logistic(double neuron){
  return 1 / (1+exp(-neuron));
}

double relu(double neuron){
  return (neuron > 0.0 ? neuron : 0.0);
}

double leaky_relu(double neuron){
  return (neuron > 0.0 ? neuron : 0.1*neuron);
}


double * softmax(double * neurons, int len){
    double sum = 0;
    int i = 0;
    for(i =0; i<len; i++){
        neurons[i] = exp(neurons[i]);
        sum += neurons[i];
    }

    for(i =0; i<len; i++){
        neurons[i] /= sum;
    }

    return neurons;
}