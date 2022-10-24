//
// Created by lolle21 on 05/02/22.
//

#ifndef PROGETTOLABORATORIO_GAMECHARACTER_H
#define PROGETTOLABORATORIO_GAMECHARACTER_H

#include "Subject.h"

class GameCharacter: public Subject {
public:
    GameCharacter(){}; //todo crea il costruttore

    void move(int x, int y);

    void registerObserver (Observer *o) override; //todo implementa
    void removeObserver (Observer * o) override; //todo implementa
    void notifyObserver () const override; //todo implementa



private:
    int x;
    int y;

};


#endif //PROGETTOLABORATORIO_GAMECHARACTER_H
