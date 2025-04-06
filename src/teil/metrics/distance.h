#ifndef __TEIL_METRICS_DISTANCE__
#define __TEIL_METRICS_DISTANCE__

#include "teil/config.h"
enum distance_metric_e{
    DISTANCE_EUCLIDEAN,
    DISTANCE_SQUARE_EUCLIDEAN,
};
feature_type euclidean_distance(feature_type * a, feature_type * b, unsigned int n_features);
feature_type sqr_euclidean_distance(feature_type * a, feature_type * b, unsigned int n_features);
feature_type calculate_distances(feature_type * a, feature_type * b, unsigned int n_features, enum distance_metric_e metric);

#endif