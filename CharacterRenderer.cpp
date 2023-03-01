//
// Created by lolle21 on 24/10/22.
//

#include "CharacterRenderer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


CharacterRenderer::CharacterRenderer() {

}

CharacterRenderer::CharacterRenderer(GameCharacter* gameCharacter) {
    gameCharacter->registerObserver(this);
    this->gameCharacter=gameCharacter;
    this->x=gameCharacter->getX();
    this->y=gameCharacter->getY();
}


void CharacterRenderer::update() {
    this->x=gameCharacter->getX();
    this->y=gameCharacter->getY();
}



sf::Sprite CharacterRenderer::renderCharacter() {
    sf::Texture texture;
    //texture.create(36,36);
    texture.loadFromFile("/home/lolle21/CLionProjects/ProgettoLaboratorio/Images/flappy_bird.png");

    sf::Sprite characterSprite;
    characterSprite.setTexture(texture);
    characterSprite.setPosition(this->x*windowSize,this->y*windowSize);
    characterSprite.scale(0.04,0.04);


    return characterSprite;

}

void CharacterRenderer::updateSpritePosition(sf::Sprite characterSprite) {
    characterSprite.setPosition(this->x, this->y);

}
