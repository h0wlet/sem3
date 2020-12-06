#ifndef LAB2_SQRT_H
#define LAB2_SQRT_H

#include "IOperation.h"
#include <math.h>
#include "NotEnoughElementsInStackException.h"
#include "NotEnoughArgumentException.h"


class Sqrt : public IOperation {
public:
    void execute(const std::list<std::string> &args, Context &context) const override{
        if (args.size() > 0) {
            throw NotEnoughArgumentsException("Command doesn't need arguments!");
        } else {
            if (context.stackSize() < 1) {
                throw NotEnoughElementsInStackException("Not enough elements in the stack!");
            } else {
                context.pushValue(sqrt(context.popValue()));
            }
        }
    }
};

#endif //LAB2_SQRT_H
