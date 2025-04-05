#include "SvcIrisLinear.h"
#include "SvcIrisPoly.h"
#include "SvcIrisRBF.h"
#include "teil/model/svm/svc.h"
#include <stdio.h>

double dataset[30][4] = {
    {6.0,2.2,5.0,1.5},
    {7.3,2.9,6.3,1.8},
    {4.8,3.0,1.4,0.1},
    {6.4,2.8,5.6,2.1},
    {5.4,3.4,1.7,0.2},
    {5.1,3.4,1.5,0.2},
    {5.0,2.3,3.3,1.0},
    {7.7,3.0,6.1,2.3},
    {5.6,3.0,4.5,1.5},
    {5.5,2.3,4.0,1.3},
    {5.2,4.1,1.5,0.1},
    {5.1,3.5,1.4,0.2},
    {7.4,2.8,6.1,1.9},
    {5.7,4.4,1.5,0.4},
    {5.8,2.7,5.1,1.9},
    {6.0,2.7,5.1,1.6},
    {6.4,3.2,4.5,1.5},
    {6.6,3.0,4.4,1.4},
    {6.7,3.1,4.7,1.5},
    {6.4,2.7,5.3,1.9},
    {5.8,2.8,5.1,2.4},
    {5.1,3.8,1.5,0.3},
    {4.4,3.0,1.3,0.2},
    {4.9,2.5,4.5,1.7},
    {4.8,3.1,1.6,0.2},
    {5.7,2.9,4.2,1.3},
    {5.2,3.4,1.4,0.2},
    {7.0,3.2,4.7,1.4},
    {6.2,3.4,5.4,2.3},
    {5.8,2.7,5.1,1.9}
};

int main(){
    unsigned int cls = 0;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 4; j++){
            SvcIrisLinear.sample[j] = dataset[i][j];
            SvcIrisPoly.sample[j] = dataset[i][j];
            SvcIrisRBF.sample[j] = dataset[i][j];
        }

        cls = svc_predict_linear(SvcIrisLinear);
        printf("%d  ", cls);
        cls = svc_predict(SvcIrisPoly);
        printf("%d  ", cls);
        cls = svc_predict(SvcIrisRBF);
        printf("%d \n", cls);
    }
    return 0;
}