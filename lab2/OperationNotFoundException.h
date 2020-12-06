#ifndef LAB2_OPERATIONNOTFOUNDEXCEPTION_H
#define LAB2_OPERATIONNOTFOUNDEXCEPTION_H

#include "CalculatorException.h"

class OperationNotFoundException : public CalculatorException{
public:
    OperationNotFoundException(const std::string &message) : CalculatorException(message){};
};

#endif //LAB2_OPERATIONNOTFOUNDEXCEPTION_H
