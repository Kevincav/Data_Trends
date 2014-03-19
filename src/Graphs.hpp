#ifndef _GRAPHS_HPP
#define _GRAPHS_HPP

#include <iostream>
#include <vector>
#include <cmath>

#include <Eigen3/Eigen/Dense>

class Graphs {
public:
    Graphs(std::pair<std::vector<float>,std::vector<float> > coords);
    float calcSalery (float years);
private:
    std::vector<float> W;
    void calcCurve(std::vector<float>& x, std::vector<float>& y, int n);
    int error(std::pair<std::vector<float>,std::vector<float> >& input, int k);
};

#endif