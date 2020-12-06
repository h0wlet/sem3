#include "OperationFactory.h"
#include "OperationNotFoundException.h"

OperationFactory &OperationFactory::getInstance() {
    static OperationFactory factory;
    return factory;
}

void OperationFactory::RegisterMaker(const std::string &name, IOperationMaker *maker){
    if (makers.find(name) != makers.end()) {
        throw OperationNotFoundException("Multiple makers for given name!");
    }
    makers[name] = maker;
}

IOperation *OperationFactory::create(const std::string &name) const{
    auto i = makers.find(name);
    if (i == makers.end()){
        throw OperationNotFoundException("Unknown operation!");
    }
    return i->second->create(name);
}
