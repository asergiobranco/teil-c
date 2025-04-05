#include <math.h>
#include "teil/model/pca/pca.h"
#include "teil/config.h"

void pca_transform(pca_model_t model){
    feature_type (* pcs)[model.n_features] = model.v;

    for(int i = 0; i< model.n_pcs; i++){
        model.scores[i] = 0.0;
        for(int j = 0; j< model.n_features; j++){
            model.scores[i] += (model.sample[j] * pcs[i][j]);
        }
    }
}

void pca_inverse(pca_model_t model){
    feature_type (* pcs)[model.n_features] = model.v;

    for(int i = 0; i< model.n_features; i++){
        model.inverse[i] = 0.0;
        for(int j = 0; j< model.n_pcs; j++){
            model.inverse[i] += (model.scores[j] * pcs[j][i]); 
        }
    }
}

void pca_error(pca_model_t model){
    for(int j = 0; j< model.n_features; j++){
        model.error[j] = (model.sample[j] - model.inverse[j]); 
    }
}

void pca_fit(pca_model_t model){

}


/*
int fit(pca_model_t model){
    svd(model.A, model.U[N_FEATURES][N_FEATURES], model.v, model.singular_values, model.explained_variance_ratio);
    return 0;
}


double calculate_eigenvalue(double A[N_FEATURES][N_FEATURES], double v[N_FEATURES]){
    double val = 0.0;
    int i = 0, j = 0;
    
    for(j=0; j < N_FEATURES; j++){
        val += (A[0][j]*v[j]);
    }

    val = (val/v[0]);
    

    return val;
}

double svd_precalculation(double A[N_FEATURES][N_FEATURES], double v[N_FEATURES]){
    
    
    double eigenvalue , eigenvalue_new = 0;
    unsigned int iterations = 0, j = 0, i = 0;
    double Av[N_FEATURES] = {0};
    double Av_norm = 0;

    // Inicia o vector v.
    for(i = 0; i < N_FEATURES; i++){
        v[i] = 0.5;
    }

    eigenvalue = calculate_eigenvalue(A, v);
    

    while(iterations < MAX_ITERATION){
        for(i = 0; i < N_FEATURES; i++){
            for(j=0; j < N_FEATURES; j++){
                Av[i] += (A[i][j]*v[j]);
            }

            Av_norm += Av[i] * Av[i];
        }

        Av_norm = sqrt(Av_norm);

        for(i = 0; i < N_FEATURES; i++){
            v[i] = Av[i] / Av_norm;
         
        }

        eigenvalue_new = calculate_eigenvalue(A, v);
        double epsilon = (eigenvalue - eigenvalue_new );
        if(epsilon < 0){
            epsilon *= -1;
        }
        if( epsilon< 0.0000000001){
            iterations = MAX_ITERATION;
        }

        eigenvalue = eigenvalue_new;

        iterations++;
    }

    return eigenvalue_new;
}

void svd(double A[N_FEATURES][N_FEATURES], double U[N_FEATURES][N_FEATURES], double v[N_FEATURES][N_FEATURES], double singular_values [N_FEATURES], double explained_variance_ratio [N_FEATURES]){
    
    
    double last_sigma = 0;
    unsigned int k = 0, j = 0, i = 0;

    for(k=0;k<N_FEATURES; k++){
        singular_values[k] = 0;
        for(i=0;i<N_FEATURES;i++){
            v[k][i] = 0.5;
            U[k][i] = 0;
        }

        if(k > 0){
            for(i=0;i<N_FEATURES;i++){
                for(j=0;j<N_FEATURES;j++){
                    A[i][j] = A[i][j] - (last_sigma * U[k-1][i] * v[k-1][j]);
                }
            }
        }
        

        svd_precalculation(A, v[k]);
        
        for(i=0;i<N_FEATURES;i++){
            for(j=0;j<N_FEATURES;j++){
                    U[k][i] += A[j][i] *  v[k][j];
            }
        }

        for(i=0;i<N_FEATURES;i++){
            singular_values[k] += (U[k][i] * U[k][i] );
        }
        
        singular_values[k] = sqrt(singular_values[k]);

        for(i=0;i<N_FEATURES;i++){
            U[k][i] = U[k][i] / singular_values[k];
        }

        last_sigma = singular_values[k];

    
    }

    for(i = 0; i < N_FEATURES; i++){
        for(j = 0; j< N_FEATURES; j++){

            // PCA model, V will become the components
            V[i][j] *= -1;
            U[j][i] = V[i][j];
            
            
            
        }
    }

    double sum = 0;
    for(i = 0; i < N_FEATURES; i++){
        sum += singular_values[i];
    }

    for(i = 0; i < N_FEATURES; i++){
        explained_variance_ratio[i] = singular_values[i] / sum;
    }
    

}

//*/