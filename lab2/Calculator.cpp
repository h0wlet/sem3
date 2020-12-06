#include "Calculator.h"

void Calculator::calculate(std::istream &stream) {
    Context context;
    std::string line;
    while (std::getline (stream, line)) {
        std::string commandName;
        std::list<std::string> args;
        std::size_t index = line.find(' ');
        commandName = line.substr(0,index);
        if (index != std::string::npos) {
            while (index != std::string::npos) {
                index++;
                line = line.substr(index++, line.length());
                std::string temp;
                index = line.find(' ');
                if (index != std::string::npos)
                    temp = line.substr(0,index);
                else
                    temp = line.substr(0);
                if (temp != "") args.push_back(temp);
            }
        }
        try {
            IOperation* operation = OperationFactory::getInstance().create(commandName);
            operation->execute(args, context);
            delete operation;
        }
        catch (std::exception& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
}
