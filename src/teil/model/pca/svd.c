#include <math.h>
#include "teil/pca/svd.h"

double calculate_eigenvalue(double * A, double * v, unsigned int n_features){
    /*
        A[n_features][n_features] -> mas so o A[0] é usado, por isso, só temos de passar o A[0]
    */
    double val = 0.0;
    int i = 0, j = 0;
    
    for(j=0; j < n_features; j++){
        //val += (A[0][j]*v[j]);
        val += (A[j]*v[j]);
    }

    val = (val/v[0]);
    

    return val;
}

double svd_precalculation(void * singular_values, double * v, double * Av, unsigned int n_features, unsigned int max_iteration){
    
    
    double eigenvalue , eigenvalue_new = 0;
    unsigned int iterations = 0, j = 0, i = 0;
    double Av_norm = 0;
    double epsilon = 0;
    double (* A)[model.n_features] = singular_values;

    // Inicia o vector v.
    for(i = 0; i < n_features; i++){
        v[i] = 0.5;
        Av[i] = 0;
    }

    eigenvalue = calculate_eigenvalue(A[0], v);
    

    while(iterations < max_iteration){
        for(i = 0; i < n_features; i++){
            for(j=0; j < n_features; j++){
                Av[i] += (A[i][j]*v[j]);
            }

            Av_norm += Av[i] * Av[i];
        }

        Av_norm = sqrt(Av_norm);

        for(i = 0; i < n_features; i++){
            v[i] = Av[i] / Av_norm;
         
        }

        eigenvalue_new = calculate_eigenvalue(A[0], v);
        epsilon = (eigenvalue - eigenvalue_new );
        if(epsilon < 0){
            epsilon *= -1;
        }
        if( epsilon< 0.0000000001){
            iterations = max_iteration;
        }

        eigenvalue = eigenvalue_new;

        iterations++;
    }

    return eigenvalue_new;
}

void svd(void * Ai, void * Ui, void * vi, double * singular_values, double * explained_variance_ratio, unsigned int n_features){
    
    double ( *A)[n_features] = Ai;
    double ( *U)[n_features] = Ui;
    double ( *v)[n_features] = vi;

    double last_sigma = 0;
    unsigned int k = 0, j = 0, i = 0;

    for(k=0;k<n_features; k++){
        singular_values[k] = 0;
        for(i=0;i<n_features;i++){
            v[k][i] = 0.5;
            U[k][i] = 0;
        }

        if(k > 0){
            for(i=0;i<n_features;i++){
                for(j=0;j<n_features;j++){
                    A[i][j] = A[i][j] - (last_sigma * U[k-1][i] * v[k-1][j]);
                }
            }
        }
        

        svd_precalculation(A, v[k]);
        
        for(i=0;i<n_features;i++){
            for(j=0;j<n_features;j++){
                    U[k][i] += A[j][i] *  v[k][j];
            }
        }

        for(i=0;i<n_features;i++){
            singular_values[k] += (U[k][i] * U[k][i] );
        }
        
        singular_values[k] = sqrt(singular_values[k]);

        for(i=0;i<n_features;i++){
            U[k][i] = U[k][i] / singular_values[k];
        }

        last_sigma = singular_values[k];

    
    }

    for(i = 0; i < n_features; i++){
        for(j = 0; j< n_features; j++){

            // PCA model, V will become the components
            V[i][j] *= -1;
            U[j][i] = V[i][j];
            
        }
    }

    double sum = 0;
    for(i = 0; i < n_features; i++){
        sum += singular_values[i];
    }

    for(i = 0; i < n_features; i++){
        explained_variance_ratio[i] = singular_values[i] / sum;
    }
    

}