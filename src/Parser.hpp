#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <iostream>
#include <vector>
#include <string>

#include <cstdio>
#include <cstdlib>

class Parser {
public:
    Parser(std::string filename);
    ~Parser();
    std::pair<std::vector<float>, std::vector<float> > getMatrix() { return std::make_pair(matrixX, matrixY); }
private:
    std::vector<float> matrixX, matrixY;
    void getMatrix(std::string filename);
};

#endif