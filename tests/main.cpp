#include <iostream>
#include <random>
#include <vector>

#include "../src/Graphs.hpp"
#include "../src/Parser.hpp"

int main(int argc, char *argv[]) {
    Parser p(argv[1]);
    Graphs g(p.getMatrix());
    
    std::cout << g.calcSalery(95) << std::endl;
    return 0;
}