#ifndef LAB2_CALCULATOR_H
#define LAB2_CALCULATOR_H

#include <iostream>
#include <fstream>
#include <list>
#include "Context.h"
#include "OperationFactory.h"
#include "OperationMaker.h"
#include "IOperation.h"
#include "IOperationMaker.h"

class Calculator {
public:
    void calculate(std::istream &stream);
};

#endif //LAB2_CALCULATOR_H

