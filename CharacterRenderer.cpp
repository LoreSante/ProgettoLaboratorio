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
}


void CharacterRenderer::update() {
    this->x=gameCharacter->getX();
    this->y=gameCharacter->getY();
}

sf::Sprite CharacterRenderer::renderCharacter() {
    sf::Texture texture;
    //texture.create(36,36);
    texture.loadFromFile("flappy_bird.png");

    sf::Sprite characterSprite;
    characterSprite.setTexture(texture);

    return characterSprite;



}
