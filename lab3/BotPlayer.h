#ifndef LAB3_BOTPLAYER_H
#define LAB3_BOTPLAYER_H

#include "Player.h"
#include <utility>

class BotPlayer : public Player {
public:
    std::pair<int,int> getMove(Model &model, Sign sign) override;
};

#endif //LAB3_BOTPLAYER_H
