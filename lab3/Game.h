#ifndef LAB3_GAME_H
#define LAB3_GAME_H

#include "Model.h"
#include "View.h"

class Game {
    static char changeSign(char sign);
    static Model doMovePerson(Model model, char sign);
    static Model doMoveBot(Model model, char sign);
    static int readPlayer(int num);
public:
    static void startGame();
};

#endif //LAB3_GAME_H
