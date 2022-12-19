//
// Created by lolle21 on 05/02/22.
//

#ifndef PROGETTOLABORATORIO_GAMECHARACTER_H
#define PROGETTOLABORATORIO_GAMECHARACTER_H

#include "Subject.h"
#include "CharacterRenderer.h"
#include <list>

class GameCharacter: public Subject {
public:

    GameCharacter(int x=0, int y=0); //todo crea il costruttore

    void moveTo(int x, int y);
    void searchPathTo(int x,int y);
    void doSteps(int x, int y);

    void registerObserver (Observer *o) override;
    void removeObserver (Observer * o) override;
    void notifyObserver () const override; //todo implementa

    int getX() const;
    int getY() const;

    void setPosition(int x, int y);

    const std::list<CharacterRenderer *> &getRenderers() const;

private:
    int x;
    int y;

    std::list<CharacterRenderer*> renderers;



};


#endif //PROGETTOLABORATORIO_GAMECHARACTER_H
