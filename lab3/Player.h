#ifndef LAB3_PLAYER_H
#define LAB3_PLAYER_H

#include <utility>
#include "Model.h"

class Player{
public:
    virtual std::pair<int,int> getMove(Model &model, Sign) = 0;
};

#endif //LAB3_PLAYER_H
