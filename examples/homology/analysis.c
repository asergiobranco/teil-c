#include "teil/data/homology/zero_dimension.h"
#include "analysis.h"

double  HomologyAnalysis_distance_values[HomologyAnalysis_DISTANCE_SIZE ] = {};
double  HomologyAnalysis_distance_values_sorted[HomologyAnalysis_DISTANCE_SIZE ] = {};
point_t HomologyAnalysis_cluster[HomologyAnalysis_N_POINTS] = {};
point_t HomologyAnalysis_seen[HomologyAnalysis_N_POINTS] = {};
point_t HomologyAnalysis_clusters_analysis_seen[HomologyAnalysis_N_POINTS] = {};
point_t HomologyAnalysis_prev_cluster[HomologyAnalysis_N_POINTS] = {};
double HomologyAnalysis_samples[HomologyAnalysis_N_POINTS][4] = {
    {0.7991525275556738,0.34978826962765586,0.3919217131763665,0.8612575789506843},
    {0.5218755578595876,0.08420734146354214,0.4097705483314288,0.9610493049465321},
    {0.8727446556725463,0.6714231161327079,0.12163329200482509,0.4153231603701317},
    {0.3940541836298398,0.5028313586163223,0.07266825034139568,0.4130716869934259},
    {0.8683687760941114,0.6148378764317947,0.07597806841170007,0.9487503938737119},
    {0.22339323353401908,0.09888698077412938,0.6787183326619776,0.8177205687313014},
    {0.958261280304438,0.1313694635799213,0.29315818985662967,0.29934003976860457},
    {0.48654243234466044,0.10154347784343065,0.9800275520455441,0.9066057071625007},
    {0.294013602671521,0.8862310191395534,0.976566391185463,0.4200477788543714},
    {0.5350158518130416,0.4596754813802084,0.7174283550944758,0.6845706565003049},
    {0.8465000666685057,0.5805145775197756,0.9303837884976152,0.8362790129690587},
    {0.47239320904643933,0.7154911741984513,0.08902662503942282,0.9634588188385735},
    {0.09215422542304175,0.41352056517416935,0.8845513529546282,0.38072738472416867},
    {0.29678276689119454,0.9134180719637512,0.05645657876716059,0.7742605174343938},
    {0.9519842715133514,0.6459975330291613,0.5728528117979503,0.8516202402708772},
    {0.34661735593270615,0.3396219963841798,0.5121615165245348,0.3221883572595252}
};
point_t HomologyAnalysis_connection_matrix[HomologyAnalysis_N_POINTS][HomologyAnalysis_N_POINTS] = {};
point_t HomologyAnalysis_clusters[15][HomologyAnalysis_N_POINTS] = {};

zero_homology_t HomologyAnalysis = {
    .n_features = 4,
    .n_points = HomologyAnalysis_N_POINTS,
    .n_clusters = 15,
    .distance_values = HomologyAnalysis_distance_values,
    .distance_values_sorted = HomologyAnalysis_distance_values_sorted,
    .cluster = HomologyAnalysis_cluster,
    .seen = HomologyAnalysis_seen,
    .clusters_analysis_seen = HomologyAnalysis_clusters_analysis_seen,
    .prev_cluster = HomologyAnalysis_prev_cluster,
    .samples = HomologyAnalysis_samples,
    .connection_matrix = HomologyAnalysis_connection_matrix,
    .clusters = HomologyAnalysis_clusters
};