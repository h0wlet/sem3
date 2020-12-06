#ifndef LAB2_DEFINE_H
#define LAB2_DEFINE_H

#include "IOperation.h"
#include "NotEnoughElementsInStackException.h"
#include "NotEnoughArgumentException.h"

class Define : public IOperation {
public:
    void execute(const std::list<std::string> &args, Context &context) const override {
        if (args.size() != 2) {
            throw NotEnoughArgumentsException("Command needs 2 arguments!");
        } else {
            std::string name = args.begin()->data();
            double val = std::stod((++(args.begin()))->data());
            context.pushConst(name, val);
        }
    }
};

#endif //LAB2_DEFINE_H
