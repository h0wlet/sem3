#include <iostream>
#include "wordCount.h"

int main() {

    wordCount obj1;
    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";
    try {
        obj1.readAndCount(inputFile);
        obj1.sortAndWrite(outputFile);
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
