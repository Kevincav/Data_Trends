#include "Graphs.hpp"

Graphs::Graphs(std::pair<std::vector<float>,std::vector<float> > coords) {
    if (coords.first.size() != coords.second.size())
        throw "BAD";
    
    int n = error(coords, 4);
    calcCurve(coords.first, coords.second, n);
}
float Graphs::calcSalery (float years) {
    float value = W[0];
    
    for (int i=1;i<W.size();++i)
        value += W[i] * std::pow(years, i);
    
    return value;
}
void Graphs::calcCurve(std::vector<float>& x, std::vector<float>& y, int n) {
    Eigen::MatrixXd matrixX(x.size(), n);
    Eigen::MatrixXd matrixY(y.size(), 1);

    for (int i=0;i<x.size();++i) {
        matrixY(i) = y[i];
        for (int j=0;j<n;++j)
            matrixX(i,j) = std::pow(x[i], j);
    }
    
    Eigen::MatrixXd inverse = matrixX.transpose() * matrixX;
    Eigen::MatrixXd final   = inverse.inverse() * matrixX.transpose() * matrixY;
    
    W.clear();
    for (int i=0;i<n;++i)
        W.push_back(final(i));
}
int Graphs::error(std::pair<std::vector<float>,std::vector<float> >& input, int k) {
    const int size   = (int) input.first.size();
    float error      = 0.f;
    float firstError = 0.f;
    int min          = 1;
    
    for (int n=1; ;++n) {
        float currError = 0.f;
        
        for (int j=0;j<k;++j) {
            const int start = j * size / k;
            const int stop  = j + 1 == k ? size : (j + 1) * size / k;
            
            std::vector<float> tempX(input.first);
            std::vector<float> tempY(input.second);
            std::vector<float> compX(tempX.begin() + start, tempX.begin() + stop);
            std::vector<float> compY(tempY.begin() + start, tempY.begin() + stop);
            tempX.erase(tempX.begin() + start, tempX.begin() + stop);
            tempY.erase(tempY.begin() + start, tempY.begin() + stop);

            calcCurve(tempX, tempY, n);
            
            float tempError = 0.f;
            for (int i=0;i<compX.size();++i)
                tempError += std::pow(calcSalery(compX[i]) - compY[i], 2);
            currError += tempError;
        }
        
        const float tmp = currError / (float) k;
        if (n == 1)
            error = firstError = tmp;
        else if (tmp > firstError)
            break;
        else if (tmp < error) {
            error = tmp;
            min = n;
        }
    }
    
    return min;
}
