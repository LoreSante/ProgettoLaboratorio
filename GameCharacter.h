//
// Created by lolle21 on 05/02/22.
//

#ifndef PROGETTOLABORATORIO_GAMECHARACTER_H
#define PROGETTOLABORATORIO_GAMECHARACTER_H

#include "Subject.h"
#include "CharacterRenderer.h"

class GameCharacter: public Subject {
public:

    GameCharacter(int x=0, int y=0); //todo crea il costruttore

    void moveTo(int x, int y);
    void searchPathTo(int x,int y);
    void doSteps(int x, int y);

    void registerObserver (Observer *o) override; //todo implementa
    void removeObserver (Observer * o) override; //todo implementa
    void notifyObserver () const override; //todo implementa

    int getX() const;
    int getY() const;

    void setPosition(int x, int y);


private:
    int x;
    int y;

};


#endif //PROGETTOLABORATORIO_GAMECHARACTER_H
