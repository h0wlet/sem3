#ifndef LAB3_MODEL_H
#define LAB3_MODEL_H

#include <iostream>
#include "View.h"
#include <list>
#include <utility>

enum class Sign {
    Cross,
    Zero
};

class Model {
    bool checkLine();
    bool checkColumn();
    bool checkDiagonal();
    char field[3][3];

    void createField();
    Sign currentPlayer = Sign::Cross;

    std::list<GameObserver*> observers;
public:
    char getField(int line, int column){
        return field[line][column];
    };

    void setField(std::pair<int, int> move, Sign s);

    void addGameObserver(GameObserver* observer){
        observers.push_back(observer);
    };
    void removeGameObserver(GameObserver* observer){
        observers.remove(observer);
    };
    void notify(){
        for(auto observer : observers){
            observer->update();
        }
    };

    Sign getCurrentPlayer();
    bool makeMove(std::pair<int,int> turn, Model &model);
    bool isEndOfGame();
    bool isFilledField();
};

#endif //LAB3_MODEL_H
