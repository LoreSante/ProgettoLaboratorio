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
    CharacterRenderer(GameCharacter* gameCharacter, int boxSize);
    void update();

    void updateSpritePosition(sf::Sprite characterSprite);

    sf::Sprite renderCharacter();

private:
    int x;
    int y;

    GameCharacter* gameCharacter;

    int boxSize;


};


#endif //PROGETTOLABORATORIO_CHARACTERRENDERER_H
