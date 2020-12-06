#include <iostream>
#include <istream>
#include "Calculator.h"

int main(const int argc, const char** argv) {
    Calculator clc;
    if (argc > 1) {
        std::ifstream fin;
        fin.open(argv[1]);
        std::istream &input = fin;
        clc.calculate(input);
    } else {
        clc.calculate(std::cin);
    }
    return 0;
}
