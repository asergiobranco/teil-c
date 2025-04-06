#include <math.h>
#include "teil/config.h"
#include "teil/metrics/distance.h"


feature_type calculate_distances(feature_type * a, feature_type * b, unsigned int n_features, enum distance_metric_e metric){
    switch(metric){
        case DISTANCE_EUCLIDEAN:
            return euclidean_distance(a, b, n_features);
            break;
        case DISTANCE_SQUARE_EUCLIDEAN:
            return sqr_euclidean_distance(a, b, n_features);
            break;
    }
}



feature_type sqr_euclidean_distance(feature_type * a, feature_type * b, unsigned int n_features){
    feature_type distance = 0;
    
    for(int i = 0; i < n_features; i++){
        distance += pow(a[i]-b[i], 2);
    }
    
    return distance;
}

feature_type euclidean_distance(feature_type * a, feature_type * b, unsigned int n_features){
    feature_type distance = 0;
    
    distance = sqr_euclidean_distance(a, b, n_features);
    
    return sqrt(distance);
}