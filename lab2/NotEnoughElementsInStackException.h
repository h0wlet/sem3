#ifndef LAB2_NOTENOUGHELEMENTSINSTACKEXPTION_H
#define LAB2_NOTENOUGHELEMENTSINSTACKEXPTION_H

#include "CalculatorException.h"

class NotEnoughElementsInStackException : public CalculatorException{
public:
    NotEnoughElementsInStackException(const std::string &message) : CalculatorException(message){};
};

#endif //LAB2_NOTENOUGHELEMENTSINSTACKEXPTION_H
