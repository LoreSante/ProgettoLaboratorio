//
// Created by lolle21 on 24/10/22.
//

#include "CharacterRenderer.h"
#include <SFML/Graphics.hpp>


CharacterRenderer::CharacterRenderer() {

}

CharacterRenderer::CharacterRenderer(GameCharacter* gameCharacter, int boxSize) {
    gameCharacter->registerObserver(this);
    this->gameCharacter=gameCharacter;
    this->x=gameCharacter->getX();
    this->y=gameCharacter->getY();
    this->boxSize=boxSize;
}
CharacterRenderer::CharacterRenderer(GameCharacter* gameCharacter) {
    gameCharacter->registerObserver(this);
    this->gameCharacter=gameCharacter;
    this->x=gameCharacter->getX();
    this->y=gameCharacter->getY();
    this->boxSize=36;
}

void CharacterRenderer::update() {
    this->x=gameCharacter->getX();
    this->y=gameCharacter->getY();
}



sf::Sprite CharacterRenderer::renderCharacter() {
    sf::Texture texture;

    texture.loadFromFile("/home/lolle21/CLionProjects/ProgettoLaboratorio/Images/flappy_bird.png");

    sf::Sprite characterSprite;
    characterSprite.setTexture(texture);
    characterSprite.setPosition(this->x*boxSize,this->y*boxSize);
    characterSprite.scale(boxSize*0.0011,boxSize*0.0011);


    return characterSprite;

}

void CharacterRenderer::updateSpritePosition(sf::Sprite characterSprite) {
    characterSprite.setPosition(this->x, this->y);

}
