#include "View.h"
#include <iostream>

void View::displayField(Model &model){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << model.getField(i,j) << " | ";
        }
        std::cout << model.getField(i,2) << std::endl;
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

void View::update() {
    if (_model.isEndOfGame()){
        cout << ((_model.getCurrentPlayer() == Sign::Cross) ? "Cross player wins!" : "Zero player wins!");
        return;
    }
    if (_model.isFilledField()){
        cout << "Draw!";
        return;
    }
    displayField(_model);
    cout << ((_model.getCurrentPlayer() == Sign::Cross) ? "Cross player turn: " : "Zero player turn: ");
}
