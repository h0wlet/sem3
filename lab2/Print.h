#ifndef LAB2_PRINT_H
#define LAB2_PRINT_H

#include "IOperation.h"
#include "NotEnoughElementsInStackException.h"
#include "NotEnoughArgumentException.h"

class Print : public IOperation {
public:
    void execute(const std::list<std::string> &args, Context &context) const override{
        if (args.size() > 0) {
            throw NotEnoughArgumentsException("Command doesn't need arguments!");
        } else {
            if (context.stackSize() < 1) {
                throw NotEnoughElementsInStackException("Not enough elements in the stack!");
            } else {
                std::cout << context.top() << std::endl;
            }
        }
    }
};


#endif //LAB2_PRINT_H
