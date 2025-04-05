#include "teil/data/homology/zero_dimension.h"
#include "analysis.h"
#include <stdio.h>

void do_analysis_example(){

    // Start the analysis
    unsigned int idx = 4;

    start_h0_analysis(&HomologyAnalysis);

    double max_distance = _max_distance(&HomologyAnalysis);

    printf("All points connected at %f\n", max_distance);

    for(idx = 0; HomologyAnalysis.distance_values_sorted[idx] <= max_distance ; idx++){
        int cluster_no = cluster_analysis(&HomologyAnalysis, HomologyAnalysis.distance_values_sorted[idx]);
        printf("NUM CLUSTERS AT %f: %d\n", HomologyAnalysis.distance_values_sorted[idx], cluster_no);
    }
    

}

int main(){
    do_analysis_example();
    return 0;
}