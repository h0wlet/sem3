#ifndef LAB2_CONTEXT_H
#define LAB2_CONTEXT_H

#include <iostream>
#include <stack>
#include <map>
#include "NotEnoughElementsInStackException.h"

class Context {
    std::stack<double> stack;
    std::map<std::string, double> vars;
public:
    int stackSize () {
        return stack.size();
    }

    void pushValue(double value){
        stack.push(value);
    }

    double popValue(){
        if (stack.empty()) {
            throw NotEnoughElementsInStackException("Stack is empty!");
        }
        double var = stack.top();
        stack.pop();
        return var;
    }

    double top() {
        return stack.top();
    }

    void pushConst(std::string &name, double &value) {
        vars[name] = value;
    }

    double getConst(std::string &name) {
        return vars.find(name)->second;
    }
};

#endif //LAB2_CONTEXT_H
