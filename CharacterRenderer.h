//
// Created by lolle21 on 24/10/22.
//

#ifndef PROGETTOLABORATORIO_CHARACTERRENDERER_H
#define PROGETTOLABORATORIO_CHARACTERRENDERER_H

#include "Observer.h"
#include <SFML/Graphics.hpp>
#include "GameCharacter.h"



class CharacterRenderer: public Observer {
public:
    CharacterRenderer();
    CharacterRenderer(GameCharacter* gameCharacter);

    void update(); //todo se serve, da implementare;

    sf::Sprite renderCharacter();

private:
    int x;
    int y;

    GameCharacter* gameCharacter;



};


#endif //PROGETTOLABORATORIO_CHARACTERRENDERER_H
