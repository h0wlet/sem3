#ifndef LAB2_CALCULATOREXCEPTION_H
#define LAB2_CALCULATOREXCEPTION_H

#include <stdexcept>
#include <string>

class CalculatorException: public std::exception {
    std::string msg;
    CalculatorException() = default;
public:
    virtual const char* what() const noexcept {
        return msg.c_str();
    }
    explicit CalculatorException(const std::string& message){
        msg = message;
    }
};

#endif //LAB2_CALCULATOREXCEPTION_H
