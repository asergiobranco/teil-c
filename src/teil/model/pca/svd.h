#ifndef __SVD__
#define __SVD__

double calculate_eigenvalue(double * A, double * v, unsigned int n_features);
double svd_precalculation(void * singular_values, double * v, double * Av, unsigned int n_features, unsigned int max_iteration);
void svd(void * Ai, void * Ui, void * vi, double * singular_values, double * explained_variance_ratio, unsigned int n_features);

#endif