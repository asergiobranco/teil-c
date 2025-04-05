#ifndef __STD_SCALER__
#define __STD_SCALER__

#include "teil/config.h"


typedef struct{
    feature_type * sample;
    unsigned int n_features;
    feature_type * mean;
    feature_type * std;
} std_scaler_t;

typedef struct{
    feature_type * sample;
    unsigned int n_features;
    feature_type * min;
    feature_type * max;
} min_max_scaler_t;

typedef enum{
    NORMALIZE_L1,
    NORMALIZE_L2,
    NORMALIZE_MAX
} normalizer_type;

typedef struct{
    feature_type * sample;
    unsigned int n_features;
    feature_type norm;
    normalizer_type type
} normalizer_scaler_t;

feature_type * std_scaler_transform(std_scaler_t model);
feature_type * std_scaler_inverse(std_scaler_t model);

feature_type * normalizer(normalizer_scaler_t model);
feature_type * minmax_transform(min_max_scaler_t model);
feature_type * minmax_inverse(min_max_scaler_t model)

//feature_type * standard_scaler(std_scaler_t scaler_conf, feature_type * sample);

#endif