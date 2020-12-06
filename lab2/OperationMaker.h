#ifndef LAB2_OPERATIONMAKER_H
#define LAB2_OPERATIONMAKER_H

#include "IOperationMaker.h"
#include "OperationFactory.h"

template<typename T>
class OperationMaker : public IOperationMaker {
public:
    OperationMaker(const std::string &name){
        OperationFactory::getInstance().RegisterMaker(name, this);
    }
    virtual IOperation *create(const std::string &name) const {
        return new T;
    }
    virtual ~OperationMaker() = default;
};

#endif //LAB2_OPERATIONMAKER_H
