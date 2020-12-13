#include "Model.h"

void Model::createField(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            field[i][j] = ' ';
        }
    }
}

bool Model::checkLine(){
    for (int i = 0; i < 3; i++){
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0]!=' ') {
            return true;
        }
    }
    return false;
}

bool Model::checkColumn(){
    for (int i = 0; i < 3; i++){
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i]!=' ') {
            return true;
        }
    }
    return false;
}

bool Model::checkDiagonal(){
    if (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0]!=' ')
        return true;
    if (field[2][0] == field[1][1] && field[1][1] == field[2][0] && field[2][0]!=' ')
        return true;
    return false;
}

bool Model::isEndOfGame(){
    if (checkLine() || checkColumn() || checkDiagonal())
        return true;
    return false;
}

bool Model::isFilledField(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (field[i][j] == ' ') return false;
        }
    }
    return true;
}
