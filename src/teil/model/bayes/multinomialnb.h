#ifndef __BAYES_MULTINOMIALNB__
#define __BAYES_MULTINOMIALNB__

typedef struct{
    unsigned int n_features;
    unsigned int n_classes;
    feature_type * sample;
    feature_type * joint_log_likelihood;//[N_CLASSES] = {0};
    feature_type * feature_log_prob_; //[N_CLASSES][N_FEATURES];
    feature_type * class_log_prior_;//[N_CLASSES];
}multinomialnb_model_t;

output_type multinomialnb_predict(multinomialnb_model_t model);

#endif