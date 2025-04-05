#ifndef __TREE__
#define __TREE__

#include "teil/config.h"
#include <stdint.h>

typedef struct{
    feature_type * sample;
    unsigned int n_features;
    unsigned int n_classes;
    void * root_node;
} dtc_model_t;

typedef struct{
    output_type output;
    float * probability;//[N_CLASSES];
} output_node_t;

typedef struct{
    feature_type threshold;
    uint8_t right_node;
    uint8_t feature;
    output_node_t * output_left;
    output_node_t * output_right;
} dt_array_node_t;

struct treeNode{
    feature_type threshold;
    struct treeNode * right;
    struct treeNode * left;
    output_node_t * output;
    uint8_t feature;
}; 

typedef struct treeNode dt_ll_node_t;

dt_ll_node_t dtc_predict_ll(dtc_model_t model);

output_node_t dtc_predict_array(dtc_model_t model);







#endif 