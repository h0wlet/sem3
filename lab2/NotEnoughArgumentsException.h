#ifndef LAB2_NOTENOUGHARGUMENTEXPTION_H
#define LAB2_NOTENOUGHARGUMENTEXPTION_H

#include "CalculatorException.h"

class NotEnoughArgumentsException : public CalculatorException{
public:
    NotEnoughArgumentsException(const std::string &message) : CalculatorException(message){};
};

#endif //LAB2_NOTENOUGHARGUMENTEXPTION_H
