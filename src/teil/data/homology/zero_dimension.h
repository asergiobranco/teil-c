#ifndef __ZERO_H_DIM__
#define __ZERO_H_DIM__

#include "teil/metrics/distance.h"
#include <stdint.h>

typedef struct{
    uint8_t point :1;
} point_t;

typedef struct{
    unsigned int n_features;
    unsigned int n_points;
    unsigned int n_clusters; //the maximum/minimum number of clusters to return
    void * samples; 
    double * distance_values; // 
    double * distance_values_sorted; // 
    void * connection_matrix;
    point_t * cluster; // n_points
    point_t * seen;  // n_points
    point_t * clusters_analysis_seen;
    point_t * prev_cluster; 
    void * clusters; //point_t ** [n_clusters][n_points]
} zero_homology_t;

/** 
* @brief T
*/
int distance_h0_compare(const void* a, const void* b);

/** 
* @brief T
*/
void start_h0_analysis(zero_homology_t * analysis);

/** 
* @brief T
*/
unsigned char h0_connection_matrix_at(zero_homology_t * analysis, unsigned int point_idx, double distance);

/** 
* @brief T
*/
int get_start_idx(unsigned int n_points, unsigned int point_no);

/** 
* @brief T
*/
int is_cluster_equal(point_t * a, point_t * b, unsigned int n_points);

/** 
* @brief T
*/
void merge_points(point_t * dest, point_t * src, unsigned int n_points);

/** 
* @brief Caclulates the distance at which all points are connected.
*
* This function computes the distance of a given zero homology analysis
* at which all points in the analysis->samples are all connected.
*
* @param analysis A pointer to a 
*
* @return The distance at which all points are connected.
*/
double _max_distance(zero_homology_t * analysis);

/**
* @brief Computes the 
*
* Computes
* 
* @param analysis 
* @param distance The distance at which to compute the cluster analysis.
*
* @return The number of clusters that exist at <distance>.
*/
unsigned int cluster_analysis(zero_homology_t * analysis, double distance);

/*
Arguments:
----------
    - analysis : zero_homology_t *
    - start_point : unsigned int
    - distance : double
*/
int h0_cluster(zero_homology_t * analysis, unsigned int start_point, double distance);

/*
This function zeroes the prev_cluster, seen, cluster.
When to use this function:
    - This function should be called when using a new distance.

Arguments:
----------
    - analysis : zero_homology_t * 
*/
void clean_analysis(zero_homology_t * analysis);

#endif