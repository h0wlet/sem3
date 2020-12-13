#ifndef LAB3_CONSOLEPLAYER_H
#define LAB3_CONSOLEPLAYER_H

#include "Model.h"
#include <utility>

class ConsolePlayer : public Model {
public:
    static Model moveConsolePlayer(Model model, std::pair<int,int> indexes, char sign);
};


#endif //LAB3_CONSOLEPLAYER_H
