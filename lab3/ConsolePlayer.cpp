#include "ConsolePlayer.h"
#include "Controller.h"

Model ConsolePlayer::moveConsolePlayer(Model model, std::pair<int,int> indexes, char sign){
    model.field[indexes.first - 1][indexes.second - 1] = sign;
    return model;
}
