cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab2 Calculator.h Context.h Division.cpp Division.cpp
        main.cpp Minus.cpp Minus.h Multiply.cpp Multiply.h
        OperationFactory.h OperationMaker.h Plus.cpp Plus.h
        Pop.cpp Pop.h Push.cpp Push.h Sqrt.cpp Sqrt.h
        IOperation.h IOperationMaker.h OperationFactory.cpp
        Define.cpp Define.h Print.cpp Print.h CalculatorException.h
        NotEnoughElementsInStackException.h NotEnoughArgumentException.h
        OperationException.h OperationNotFoundException.h Calculator.cpp)
