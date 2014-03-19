#include "Graphs.hpp"

Graphs::Graphs(std::pair<std::vector<float>,std::vector<float> >& coords) {
    if (coords.first.size() != coords.second.size())
        throw "BAD";
    
    calcCurve(coords.first, coords.second);
}
~Graphs::Graphs() {
    
}
float Graphs::calcSalery (float years) {
    float value = W[i];
    for (int i=1;i<W.size();++i)
        value += W[i] * std::pow(years, i);
    return value;
}
void Graphs::calcCurve(std::vector<float>& x, std::vector<float>& y) {
    int n = 4;

    Eigen::matrixXd matrixX(x.size(), x[0].size(), CV_32F);
    Eigen::matrixXd matrixY(y.size(), 1, CV_32F);
    
    for (int i=0;i<x.size();++i) {
        matrixY.at<float>(i) = y[i];
        for (int j=0;j<n;++j)
            matrixX.at<float>(i,j) = std::pow(x[i], j);
    }
    
    // TODO inv(X' * X) * X' * Y
}