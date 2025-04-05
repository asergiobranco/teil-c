
#include "SvcIrisPoly.h"
#include "teil/config.h"
#include "teil/model/svm/svc.h"
#include "teil/model/preprocessing/kernel.h"
#include <stddef.h>

feature_type SvcIrisPoly_sample[4];
feature_type SvcIrisPoly_kernels[20];
feature_type SvcIrisPoly_sv[20][4] = {
    {5.1,3.3,1.7,0.5},
	{4.8,3.4,1.9,0.2},
	{4.5,2.3,1.3,0.3},
	{5.1,3.8,1.9,0.4},
	{6.1,2.9,4.7,1.4},
	{5.6,3.0,4.5,1.5},
	{6.2,2.2,4.5,1.5},
	{5.9,3.2,4.8,1.8},
	{6.3,2.5,4.9,1.5},
	{6.7,3.0,5.0,1.7},
	{6.0,2.7,5.1,1.6},
	{5.4,3.0,4.5,1.5},
	{5.1,2.5,3.0,1.1},
	{4.9,2.5,4.5,1.7},
	{6.0,2.2,5.0,1.5},
	{6.3,2.7,4.9,1.8},
	{6.2,2.8,4.8,1.8},
	{6.1,3.0,4.9,1.8},
	{6.3,2.8,5.1,1.5},
	{6.0,3.0,4.8,1.8}
};

feature_type SvcIrisPoly_weights[3-1][20] = {
    {0.5256715686008866,0.0,0.029973422330933305,0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0,-0.55564499093182,-0.1074451016617149,-0.0,-0.0,-0.0,-0.0,-0.0,-0.0},
	{0.030213746660517862,0.036900359151084,0.0,0.04033099585011306,0.015622358913985099,0.8098069761580579,1.0,1.0,1.0,1.0,1.0,1.0,0.0,-1.0,-0.8254293350720429,-1.0,-1.0,-1.0,-1.0,-1.0}
};

feature_type SvcIrisPoly_intercepts[3] = {1.1346038567888097,1.1840816486018733,3.6379873916673424};
feature_type SvcIrisPoly_rules[3] = {0.0};
unsigned int SvcIrisPoly_ranges[3+1] = {0,4,13,20};
unsigned int SvcIrisPoly_amounts[3] = {0};

svc_model_t SvcIrisPoly = {
    .n_support = 20,
    .n_intercepts = 3,
    .n_classes = 3,
    .n_features = 4,
    .degree = 3,
    .gamma = 0.06416744863614975,
    .coef = 0.0,
    .kernel = KERNEL_POLY,
    .kernels = SvcIrisPoly_kernels,
    .support_vectors =  SvcIrisPoly_sv,
    .weights = SvcIrisPoly_weights,
    .ranges = SvcIrisPoly_ranges,
    .intercepts = SvcIrisPoly_intercepts,
    .sample = SvcIrisPoly_sample,
    .decision_rules = SvcIrisPoly_rules,
    .amounts = SvcIrisPoly_amounts
};

