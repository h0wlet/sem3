#include "Controller.h"
#include <iostream>

using namespace std;

std::pair<int,int> Controller::readLineAndColumn(){
    cout << "Enter line and column: " << endl;
    int line, column;
    cin >> line >> column;
    return {line, column};
}
