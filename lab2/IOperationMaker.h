#ifndef LAB2_IOPERATIONMAKER_H
#define LAB2_IOPERATIONMAKER_H

#include "IOperation.h"

class IOperation;
class IOperationMaker {
public:
    virtual IOperation *create(const std::string &name) const = 0;
    virtual ~IOperationMaker() = default;
};

#endif //LAB2_IOPERATIONMAKER_H
