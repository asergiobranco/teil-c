#include "teil/config.h"
#include "teil/model/tree/tree.h"
#include <stddef.h>
#include <stdint.h>

dt_ll_node_t dt_predict_ll(dtc_model_t model){

    dt_ll_node_t * root = (dt_ll_node_t *) model.root_node;

    while(root->right != NULL){
        if(model.sample[root->feature] < root->threshold){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    return *root;

}

output_node_t dt_predict_array(dtc_model_t model){
    dt_array_node_t * nodes = (dt_array_node_t * ) model.root_node;

    unsigned int i = 0;
    unsigned int stop = 0;
    while(!stop){ 
        if(model.sample[nodes[i].feature] < nodes[i].threshold){
            if(nodes[i].output_left != NULL){
                return *nodes[i].output_left; 
            }
            i++;
        }
        else{
            if(nodes[i].output_right != NULL){
                return *nodes[i].output_right;
            }
            i = nodes[i].right_node;
        }
    }
}
