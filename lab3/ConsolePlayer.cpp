#include "ConsolePlayer.h"
#include "Controller.h"

std::pair<int,int> ConsolePlayer::getMove(Model &model, Sign sign){
    return Controller::readLineAndColumn();
}
