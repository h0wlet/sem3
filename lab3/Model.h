#ifndef LAB3_MODEL_H
#define LAB3_MODEL_H

class Model {
    bool checkLine();
    bool checkColumn();
    bool checkDiagonal();

public:
    char field[3][3];
    void createField();
    bool isEndOfGame();
    bool isFilledField();
};

#endif //LAB3_MODEL_H
