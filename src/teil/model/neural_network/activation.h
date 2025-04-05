#ifndef __ACTIVATION__
#define __ACTIVATION__

#define ACTIVATION_TANH 0
#define ACTIVATION_SIGMOID 1
#define ACTIVATION_LOGISTIC 2
#define ACTIVATION_RELU 3
#define ACTIVATION_LEAKY_RELU 4
#define ACTIVATION_SOFTMAX 5
#define ACTIVATION_IDENTITY 6
#define ACTIVATION_SWISH 7

double identity(double neuron);
double logistic(double neuron);
double relu(double neuron);
double leaky_relu(double neuron);
double * softmax(double * neurons, int len);

#endif