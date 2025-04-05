#ifndef __ANALYSIS__ 
#define __ANALYSIS__

#include "teil/data/homology/zero_dimension.h"

#define HomologyAnalysis_N_POINTS 16 
#define HomologyAnalysis_DISTANCE_SIZE ((HomologyAnalysis_N_POINTS*HomologyAnalysis_N_POINTS) - HomologyAnalysis_N_POINTS)/2

extern double  HomologyAnalysis_distance_values[HomologyAnalysis_DISTANCE_SIZE ];
extern double  HomologyAnalysis_distance_values_sorted[HomologyAnalysis_DISTANCE_SIZE ];
extern point_t HomologyAnalysis_cluster[HomologyAnalysis_N_POINTS];
extern point_t HomologyAnalysis_seen[HomologyAnalysis_N_POINTS];
extern point_t HomologyAnalysis_prev_cluster[HomologyAnalysis_N_POINTS];
extern double HomologyAnalysis_samples[HomologyAnalysis_N_POINTS][4];
extern point_t HomologyAnalysis_connection_matrix[HomologyAnalysis_N_POINTS][HomologyAnalysis_N_POINTS];
extern point_t HomologyAnalysis_clusters[15][HomologyAnalysis_N_POINTS];
extern point_t HomologyAnalysis_clusters_analysis_seen[HomologyAnalysis_N_POINTS];

extern zero_homology_t HomologyAnalysis;

#endif 
