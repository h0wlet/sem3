#ifndef LAB2_PUSH_H
#define LAB2_PUSH_H

#include "IOperation.h"
#include "NotEnoughArgumentException.h"

class Push : public IOperation {
public:
    void execute(const std::list<std::string> &args, Context &context) const override{
        if (args.size() > 1) {
            throw NotEnoughArgumentsException("Command needs 1 argument!");
        } else {
            char symbol = args.begin()->data()[0];
            if(symbol >= '0' && symbol <= '9'){
                double value = std::stod(args.begin()->data());
                context.pushValue(value);
            } else {
                std::string nameOfVal = *(args.begin());
                context.pushValue(context.getConst(nameOfVal));
            }
        }


    }
};


#endif //LAB2_PUSH_H
