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

Sign Model::getCurrentPlayer() {
    if (currentPlayer == Sign::Cross)
        return Sign::Cross;
    else
        return Sign::Zero;
}

bool Model::makeMove(std::pair<int,int> turn, Model &model){
    if (turn.first < 1 || turn.first > 3 || turn.second < 1 || turn.second >3)
        return false;
    else {
        setField(turn, getCurrentPlayer());
        Model::notify();
        if (currentPlayer == Sign::Cross)
            currentPlayer = Sign::Zero;
        else
            currentPlayer = Sign::Cross;
        return true;
    }
}

void Model::setField(std::pair<int, int> move, Sign s){
    char sign;
    if (s == Sign::Cross) sign = 'x';
    else sign = 'o';
    field[move.first][move.second] = sign;
};
