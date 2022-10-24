//
// Created by lolle21 on 24/10/22.
//

#ifndef PROGETTOLABORATORIO_CHARACTERRENDERER_H
#define PROGETTOLABORATORIO_CHARACTERRENDERER_H
#include "Observer.h"
#include "GameCharacter.h"

class CharacterRenderer: public Observer {


    void update(); //todo se serve, da implementare;


private:
    GameCharacter* character;
};


#endif //PROGETTOLABORATORIO_CHARACTERRENDERER_H
