#include "Controller.h"
#include <iostream>
using namespace std;

std::pair<int,int> Controller::readLineAndColumn(){
    int line, column;
    cin >> line >> column;
    while (line < 1 || line > 3 || column < 1 || column > 3){
        cout << "Values entered incorrectly!" << endl;
        cout << "Enter line and column: " << endl;
        cin >> line >> column;
    }
    return {line, column};
}
