#ifndef LAB3_BOTPLAYER_H
#define LAB3_BOTPLAYER_H

#include "Model.h"
#include <utility>

class BotPlayer : public Model {
    static std::pair<int,int> checkPlace(Model model);
public:
    static Model moveBotPlayer(Model model, char sign);

};

#endif //LAB3_BOTPLAYER_H
