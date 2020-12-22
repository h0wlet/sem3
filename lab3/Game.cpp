#include "Game.h"
#include "Controller.h"
#include "ConsolePlayer.h"
#include "BotPlayer.h"
#include <iostream>
#define Person 1
//#define Bot 2

void Game::startGame(){
    Model model{};
    View view(model);

    View::chooseGamer(1);
    Player *player1 = (readPlayer(1) == Person) ? new ConsolePlayer : new BotPlayer;
    View::chooseGamer(2);
    Player *player2 = (readPlayer(2) == Person) ? new ConsolePlayer : new BotPlayer;

    while (!model.isEndOfGame()) {
        pair<int, int> move;
        if (model.getCurrentPlayer() == Sign::Cross)
            move = player1->getMove(model, Sign::Cross);
        else
            move = player2->getMove(model, Sign::Zero);

        if (!model.makeMove(move, model))
            cout << "Values entered incorrectly!" << endl;
    }
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
