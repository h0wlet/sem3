#include "Game.h"
#include "Controller.h"
#include "ConsolePlayer.h"
#include "BotPlayer.h"
#include <iostream>
#define Person 1
#define Bot 2

using namespace std;

void Game::startGame(){
    Model model{};
    model.createField();
    View::chooseGamer(1);
    int firstPlayer, secondPlayer;
    firstPlayer = readPlayer(1);
    View::chooseGamer(2);
    secondPlayer = readPlayer(2);
    cout << "Choose a sign for the first player: x or o?";
    char sign;
    cin >> sign;
    while (sign != 'x' && sign != 'o') {
        cout << "Unknown sign!" << endl;
        cout << "Choose your sign: x or o? ";
        cin >> sign;
    }
    sign = changeSign(sign);
    while (!model.isEndOfGame()) {
        sign = changeSign(sign);
        switch (firstPlayer) {
            case Person:
                model = doMovePerson(model, sign);
                break;
            case Bot:
                model = doMoveBot(model, sign);
                break;
            default:
                return;
        }
        if (model.isEndOfGame()){
            cout << "First player wins!";
            return;
        }
        if (model.isFilledField()){
            cout << "Draw!";
            return;
        }
        sign = changeSign(sign);
        switch (secondPlayer) {
            case Person:
                model = doMovePerson(model, sign);
                break;
            case Bot:
                model = doMoveBot(model, sign);
                break;
            default:
                return;
        }
        if (model.isEndOfGame()){
            cout << "Second player wins!";
            return;
        }
        if (model.isFilledField()){
            cout << "Draw!";
            return;
        }
    }
}

char Game::changeSign(char sign){
    if (sign == 'x')
        return 'o';
    else return 'x';
}

Model Game::doMovePerson(Model model, char sign){
    View::displayField(model);
    cout << "Enter line and column: " << endl;
    model = ConsolePlayer::moveConsolePlayer(model, Controller::readLineAndColumn(), sign);
    return model;
}

Model Game::doMoveBot(Model model, char sign){
    model = BotPlayer::moveBotPlayer(model, sign);
    return model;
}

int Game::readPlayer(int num){
    int player;
    cin >> player;
    while (player != 1 && player != 2) {
        cout << "Unknown type!" << endl;
        View::chooseGamer(num);
        cin >> player;
    }
    return player;
}
