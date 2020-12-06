#ifndef LAB2_IOPERATION_H
#define LAB2_IOPERATION_H

#include <string>
#include <list>
#include "Context.h"

#define REGISTER_OPERATION(T, NAME) static OperationMaker<T> maker(NAME);

class IOperation {
public:
    virtual void execute(const std::list<std::string> &args, Context &context) const = 0;
    virtual ~IOperation() = default;
};

#endif //LAB2_IOPERATION_H
