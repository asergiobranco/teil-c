#ifndef __DTR__
#define __DTR__

#include "teil/config.h"
#include <stdint.h>

typedef struct{
    feature_type * sample;
    unsigned int n_features;
    void * root_node;
} dtr_model_t;

typedef struct{
    double output;
} dtr_output_node_t;

typedef struct{
    feature_type threshold;
    uint8_t right_node;
    uint8_t feature;
    dtr_output_node_t * output_left;
    dtr_output_node_t * output_right;
} dtr_array_node_t;

struct dtr_treeNode{
    feature_type threshold;
    struct dtr_treeNode * right;
    struct dtr_treeNode * left;
    dtr_output_node_t * output;
    uint8_t feature;
}; 

typedef struct dtr_treeNode dtr_ll_node_t;

dtr_ll_node_t dtr_predict_ll(dtr_model_t model);

dtr_output_node_t dtr_predict_array(dtr_model_t model);







#endif 