#ifndef LAB3_CONSOLEPLAYER_H
#define LAB3_CONSOLEPLAYER_H

#include "Player.h"
#include <utility>

class ConsolePlayer : public Player {
public:
    std::pair<int,int> getMove(Model &model, Sign sign) override;
};


#endif //LAB3_CONSOLEPLAYER_H
