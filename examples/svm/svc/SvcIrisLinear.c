
#include "SvcIrisLinear.h"
#include "teil/config.h"
#include "teil/model/svm/svc.h"
#include "teil/model/preprocessing/kernel.h"
#include <stddef.h>

feature_type SvcIrisLinear_sample[4];

feature_type SvcIrisLinear_sv[3][4] = {
    {-0.046258538085542256,0.5211827995531007,-1.0030446153124941,-0.4641297849669344},
	{-0.007223125656643181,0.1789412101069795,-0.5383645876794639,-0.2923926281681868},
	{0.5954977630181517,0.973900296706443,-2.03099957569016,-2.0063026699090667}
};

feature_type SvcIrisLinear_intercepts[3] = {1.4528444969775751,1.5077131251781049,6.780971185110271};
feature_type SvcIrisLinear_rules[3] = {0.0};
unsigned int SvcIrisLinear_amounts[3] = {0};

svc_model_t SvcIrisLinear = {
    .n_support = 3,
    .n_intercepts = 3,
    .n_classes = 3,
    .n_features = 4,
    .degree = 0,
    .gamma = 0.0,
    .coef = 0.0,
    .kernel = KERNEL_LINEAR,
    .kernels = NULL,
    .support_vectors =  NULL,
    .weights = SvcIrisLinear_sv,
    .ranges = NULL,
    .intercepts = SvcIrisLinear_intercepts,
    .sample = SvcIrisLinear_sample,
    .decision_rules = SvcIrisLinear_rules,
    .amounts = SvcIrisLinear_amounts
};

