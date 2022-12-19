//
// Created by lolle21 on 24/10/22.
//

#ifndef PROGETTOLABORATORIO_CHARACTERRENDERER_H
#define PROGETTOLABORATORIO_CHARACTERRENDERER_H

#include "Observer.h"


class CharacterRenderer: public Observer {
public:
    CharacterRenderer();
    //CharacterRenderer(GameCharacter*)

    void update(); //todo se serve, da implementare;


private:

};


#endif //PROGETTOLABORATORIO_CHARACTERRENDERER_H
