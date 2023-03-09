#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MapRenderer.h"
#include "Map.h"
#include "GameCharacter.h"
#include "CharacterRenderer.h"

using namespace std;

int main( int argc, char *argv[] )
{
    int const sizeWindow = 720;

    Map *map=new Map();

    MapRenderer *mapRenderer=new MapRenderer(map);

    int sizeDivisor = sizeWindow/map->getMapWidth();

    GameCharacter* gameCharacter=new GameCharacter(0, 0);

    CharacterRenderer* characterRenderer=new CharacterRenderer(gameCharacter, sizeDivisor);

    sf::RenderWindow window(sf::VideoMode(sizeWindow, sizeWindow), "Mappa di gioco");
    sf::Sprite mapSprite;
    sf::Texture mapTexture;

    sf::Vector2i position;

    mapRenderer->renderMap(sizeWindow,sizeWindow);

    bool mousePressedFlag=false;

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mousePressedFlag = true;
            position= sf::Mouse::getPosition(window);
            cout << "Mouse Position: (" << position.x << ", " << position.y << ")";
        }

        if(mousePressedFlag) {
            if (!(gameCharacter->isArrivedTo(position.x / sizeDivisor, position.y / sizeDivisor))) {
                gameCharacter->setStarAndGoal(position.x / sizeDivisor, position.y / sizeDivisor);
                if (gameCharacter->searchPath()) {
                    gameCharacter->doStep();
                }
            }else {
                mousePressedFlag = false;
            }
        }

        window.draw(mapRenderer->getMapSprite());
        window.draw(characterRenderer->renderCharacter());
        window.display();

    }

    return 0;
}