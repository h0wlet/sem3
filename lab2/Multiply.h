#ifndef LAB2_MULTIPLY_H
#define LAB2_MULTIPLY_H

#include "IOperation.h"
#include "NotEnoughElementsInStackException.h"
#include "NotEnoughArgumentException.h"

class Multiply : public IOperation {
public:
    void execute(const std::list<std::string> &args, Context &context) const override {
        if (args.size() > 0) {
            throw NotEnoughArgumentsException("Command doesn't need arguments!");
        } else {
            if (context.stackSize() < 2) {
                throw NotEnoughElementsInStackException("Not enough elements in the stack!");
            } else {
                context.pushValue(context.popValue() * context.popValue());
            }
        }
    }
};


#endif //LAB2_MULTIPLY_H
