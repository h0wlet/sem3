#include "View.h"
#include <iostream>

using namespace std;

void View::displayField(Model m){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << m.field[i][j] << " | ";
        }
        std::cout << m.field[i][2] << std::endl;
        if (i != 2) std::cout << "---------" << std::endl;
    }
    std::cout << std::endl;
}

void View::chooseGamer(int num) {
    if (num == 1)
        cout << "Select the first player: " << endl;
    else cout << "Select the second player: " << endl;
    cout << "1.Person" << endl;
    cout << "2.BotPlayer" << endl;
    cout << "Enter only number!" << endl;
}
