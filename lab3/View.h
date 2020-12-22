#ifndef LAB3_VIEW_H
#define LAB3_VIEW_H

#include "GameObserver.h"
#include "Model.h"

using namespace std;

class View : GameObserver {
    Model &_model;
public:
    view(Model &model) : _model(model){
        model.addGameObserver(this);
    };
    static void displayField(Model &model);
    static void chooseGamer(int num);
    void update() override;
};

#endif //LAB3_VIEW_H
