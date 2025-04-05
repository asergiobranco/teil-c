#include "teil/metrics/distance.h"
#include "teil/data/homology/zero_dimension.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


int distance_h0_compare(const void* a, const void* b){
    double i = *(double*)a;
    double j = *(double*)b;
    if(i < j){
        return -1;
    }

    return 1;
}
void start_h0_analysis(zero_homology_t * analysis){
    int d  = 0;
    double (*samples)[analysis->n_features] = analysis->samples;
    for(int i = 0; i < analysis->n_points; i++){
        for(int j = i+1; j < analysis->n_points; j++){
            analysis->distance_values[d] = sqr_euclidean_distance(samples[i], samples[j], analysis->n_features);
            analysis->distance_values_sorted[d] = analysis->distance_values[d];
            d++;
        }
    }
    qsort(analysis->distance_values_sorted, d, sizeof(double), distance_h0_compare);
    d = 0;
    for(int i = 0; i < analysis->n_points; i++){
        for(int j = i+1; j < analysis->n_points; j++){
            d++;
        }
    }
}


unsigned char h0_connection_matrix_at(zero_homology_t * analysis, unsigned int point_idx, double distance){
    int d  = 0;
    point_t (*connection_matrix)[analysis->n_points] = analysis->connection_matrix;
    unsigned char is_connected = 0;
    for(int i = 0; i < analysis->n_points; i++){
        for(int j = i+1; j < analysis->n_points; j++){
            if(i==point_idx || j==point_idx){
                if(analysis->distance_values[d] <= distance){
                    connection_matrix[i][j].point = 1;
                    connection_matrix[j][i].point = 1;
                    is_connected+=1;
                }
                else{
                    connection_matrix[i][j].point = 0;
                    connection_matrix[j][i].point = 0;
                }
            }
            d++;
        }
    }
    return is_connected;
}

/* para quando tiver a formula
void h0_connection_matrix_at(zero_homology_t * analysis, double distance){
    int d  = 0;
    point_t (*connection_matrix)[analysis->n_points] = analysis->connection_matrix;

    for(int i = 0; i < analysis->n_points; i++){
        for(int j = i+1; j < analysis->n_points; j++){
            if(analysis->distance_values[d] <= distance){
                connection_matrix[d].point = 1;
            }
            else{
                analysis->connection_matrix[d].point = 0; 
            }
            d++;
        }
    }
}
*/

// poitn should start at 0
int get_start_idx(unsigned int n_points, unsigned int point_no){
    
    if(point_no == 0){
        return 0;
    }

    if(point_no >= (n_points-1))
        return -1;

    return (point_no * n_points) - (point_no-1) - ((point_no * (point_no-1))/2);

}

int is_cluster_equal(point_t * a, point_t * b, unsigned int n_points){
    for(int i = 0; i < n_points; i++){
        if(a[i].point != b[i].point){
            return 0;
        }
    }

    return 1;
}




void merge_points(point_t * dest, point_t * src, unsigned int n_points){
    for(int i = 0; i < n_points; i++){
        dest[i].point |= src[i].point;
    }
}

double _max_distance(zero_homology_t * analysis){

    //Comeca a meio
    unsigned int start_point = ((analysis->n_points * analysis->n_points) - analysis->n_points) / 4;
    int inc = 0, i = 0, stop_condition;
    unsigned char points = 0;
    double max_distance = analysis->distance_values_sorted[start_point];
    
    points = h0_cluster(analysis, 0, analysis->distance_values_sorted[start_point]);
    
    if(points == analysis->n_points){
        inc = -1;
        stop_condition = 0;
    }
    else{
        inc = +1;
        stop_condition = 1;
    }

    i = start_point;

    while((points == analysis->n_points) != stop_condition){
        i += inc;
        points = h0_cluster(analysis, 0, analysis->distance_values_sorted[i]); 
    }

    max_distance = analysis->distance_values_sorted[i-(inc)];

    return max_distance;

}

/*

*/

void clean_analysis(zero_homology_t * analysis){
    for(int i  = 0; i < analysis->n_points; i++ ){
        // poe os dois com o valor do ponto a partir do qual queremos o cluster
        analysis->cluster[i].point = 0;
        analysis->prev_cluster[i].point = 0;
        analysis->seen[i].point = 0;
    }
}

unsigned int cluster_analysis(zero_homology_t * analysis, double distance){
    point_t (*clusters)[analysis->n_points] = analysis->clusters;
    unsigned char num_of_points = 0;
    int clusters_number = 0;
    for(int j = 0; j < analysis->n_points; j++){
        analysis->clusters_analysis_seen[j].point = 0;
    }

    for(int i = 0; i < analysis->n_clusters; i++){

        for(int j = 0; j < analysis->n_points; j++){
            if(analysis->clusters_analysis_seen[j].point == 0){
                clusters_number += 1;
                analysis->clusters_analysis_seen[j].point = 1;
                num_of_points = h0_cluster(analysis, j, distance);
                if(num_of_points != 0){
                    //printf("Cluster at %f distance with %d points: ", distance, num_of_points);
                    for(int k = 0; k < analysis->n_points; k++){
                        //printf("%d", analysis->cluster[k].point);
                        clusters[i][k].point = analysis->cluster[k].point; 
                        analysis->clusters_analysis_seen[k].point |= analysis->cluster[k].point;
                    }
                    //printf("\n");
                    
                }
                
            }


            
            
        }

        

    }

    return clusters_number;
}

int h0_cluster(zero_homology_t * analysis, unsigned int start_point, double distance){
    unsigned char connected_count = 0;
    point_t (*connection_matrix)[analysis->n_points] = analysis->connection_matrix;
    
    connected_count = h0_connection_matrix_at(analysis, start_point, distance);

    if(connected_count == 0){
        return 0;
    }
   

    for(int i  = 0; i < analysis->n_points; i++ ){
        analysis->cluster[i].point = connection_matrix[start_point][i].point;
        analysis->prev_cluster[i].point = 0;
        analysis->seen[i].point = 0;
        //printf("%d %d\n", connection_matrix[start_point][i].point, analysis->cluster[i].point);
        
    }
    connected_count = 0;
    while(!is_cluster_equal(analysis->cluster, analysis->prev_cluster, analysis->n_points)){
        // copia os pontos
        merge_points( 
            analysis->prev_cluster, 
            analysis->cluster, 
            analysis->n_points
        );

        for(int i  = 0; i < analysis->n_points; i++ ){
            if(analysis->cluster[i].point == 1 && analysis->seen[i].point == 0){
                //printf("%d connected to %d\n", start_point, i);
                analysis->seen[i].point = 1;
                connected_count += 1;
                h0_connection_matrix_at(analysis, i, distance);
                merge_points(  
                    analysis->cluster,
                    connection_matrix[i],
                    analysis->n_points
                );
            }
        }
    }
    return connected_count;

}