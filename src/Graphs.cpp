#include "Graphs.hpp"

Graphs::Graphs(std::pair<std::vector<float>,std::vector<float> > coords) {
    if (coords.first.size() != coords.second.size())
        throw "BAD";
    
    calcCurve(coords.first, coords.second);
}
float Graphs::calcSalery (float years) {
    float value = W[0];
    for (int i=1;i<W.size();++i)
        value += W[i] * std::pow(years, i);
    return value;
}
void Graphs::calcCurve(std::vector<float>& x, std::vector<float>& y) {
    int n = 4;

    Eigen::MatrixXd matrixX(x.size(), n);
    Eigen::MatrixXd matrixY(y.size(), 1);

    for (int i=0;i<x.size();++i) {
        matrixY(i) = y[i];
        for (int j=0;j<n;++j)
            matrixX(i,j) = std::pow(x[i], j);
    }
    Eigen::MatrixXd inverse = matrixX.transpose() * matrixX;
    Eigen::MatrixXd final   = inverse.inverse() * matrixX.transpose() * matrixY;
    
    for (int i=0;i<n;++i)
        W.push_back(final(i));
}