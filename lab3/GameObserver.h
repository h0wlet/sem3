#ifndef LAB3_GAMEOBSERVER_H
#define LAB3_GAMEOBSERVER_H

class GameObserver {
public:
    virtual ~GameObserver() = default;
    virtual void update() = 0;
};

#endif //LAB3_GAMEOBSERVER_H
