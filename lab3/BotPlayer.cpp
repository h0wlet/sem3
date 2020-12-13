#include "Model.h"
#include "BotPlayer.h"

std::pair<int,int> BotPlayer::checkPlace(Model model){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (model.field[i][j] == ' ')
                return {i,j};
        }
    }
}

Model BotPlayer::moveBotPlayer(Model model, char sign){
    std::pair<int,int> indexes = checkPlace(model);
    model.field[indexes.first][indexes.second] = sign;
    return model;
}
