#ifndef LAB2_OPERATIONEXCEPTION_H
#define LAB2_OPERATIONEXCEPTION_H

#include "CalculatorException.h"

class OperationException : public CalculatorException{
public:
    OperationException(const std::string &message) : CalculatorException(message){};
};

#endif //LAB2_OPERATIONEXCEPTION_H
