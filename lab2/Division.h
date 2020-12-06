#ifndef LAB2_DIVISION_H
#define LAB2_DIVISION_H

#include "IOperation.h"
#include "NotEnoughElementsInStackException.h"
#include "NotEnoughArgumentException.h"
#include "OperationException.h"

class Division : public IOperation {
public:
    void execute(const std::list<std::string> &args, Context &context) const override{
        if (args.size() > 0) {
            throw NotEnoughArgumentsException("Command doesn't need arguments!");
        } else {
            if (context.stackSize() < 2) {
                throw NotEnoughElementsInStackException("Not enough elements in the stack!");
            } else {
                auto a1 = context.popValue();
                auto a2 = context.popValue();
                if (a2 == 0) {
                    throw OperationException("Division by zero!");
                }
                context.pushValue(a1 / a2);
            }
        }
    }
};


#endif //LAB2_DIVISION_H
