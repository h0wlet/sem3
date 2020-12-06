#ifndef LAB2_POP_H
#define LAB2_POP_H

#include "IOperation.h"
#include "NotEnoughArgumentException.h"
#include "NotEnoughElementsInStackException.h"

class Pop : public IOperation {
public:
    void execute(const std::list<std::string> &args, Context &context) const override{
        if (args.size() > 0) {
            throw NotEnoughArgumentsException("Command doesn't need arguments!");
        } else {
            if (context.stackSize() == 0) {
                throw NotEnoughElementsInStackException("Stack is empty!");
            } else {
                context.popValue();
            }
        }
    }
};

#endif //LAB2_POP_H
