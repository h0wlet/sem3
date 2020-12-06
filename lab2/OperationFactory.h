#ifndef LAB2_OPERATIONFACTORY_H
#define LAB2_OPERATIONFACTORY_H

#include <map>
#include <string>
#include "IOperation.h"
#include "IOperationMaker.h"

class OperationFactory {
    OperationFactory() = default;
    std::map<std::string, IOperationMaker*> makers;
public:
    static OperationFactory &getInstance();
    void RegisterMaker(const std::string &name, IOperationMaker *maker);
    IOperation *create(const std::string &name) const;
};

#endif //LAB2_OPERATIONFACTORY_H
