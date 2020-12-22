#include "Model.h"
#include "BotPlayer.h"

std::pair<int,int> BotPlayer::getMove(Model &model, Sign sign) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (model.getField(i,j) == ' ')
                return {i,j};
        }
    }
}
