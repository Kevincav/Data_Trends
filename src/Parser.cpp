#include "Parser.hpp"

Parser::Parser(std::string filename) {
    getMatrix(filename);
}
void Parser::getMatrix(std::string filename) {
    FILE *fp = fopen(filename.c_str(), "r");
    float x, y;
    std::vector<std::vector<float> > map;
    std::vector<float> temp(2);
    
    while (fscanf(fp, "%f,%f", &x, &y) != EOF) {
        matrixX.push_back(x);
        matrixY.push_back(y);
    }
    
    fclose(fp);
}