#include <iostream>

#include "fsa.h"
#include "stlastar.h"
#include "findpath.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MapRenderer.h"
#include "Map.h"
#include "GameCharacter.h"
#include "CharacterRenderer.h"

using namespace std;



int main( int argc, char *argv[] )
{
    int const sizeDivisor=36;
    //void renderMap(int length, int height,sf::Sprite &sprite, sf::Texture &textureMap);
    Map *map=new Map();
    MapRenderer *mapRenderer=new MapRenderer(map);

    GameCharacter* gameCharacter=new GameCharacter(0, 0);
    //gameCharacter->moveTo(16,5);

    CharacterRenderer* characterRenderer=new CharacterRenderer(gameCharacter);

    sf::RenderWindow window(sf::VideoMode(720, 720), "Mappa di gioco bruttissima");
    sf::Sprite mapSprite;
    sf::Texture mapTexture;

    sf::Vector2i position;

    /*
    mapRenderer->renderMap(720,720, mapSprite,mapTexture);
    mapSprite.setTexture(mapTexture);
    */
    mapRenderer->renderMap(720,720);

    bool mousePressedFlag=false;



    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        //gameCharacter->moveTo(0,0);
        //gameCharacter->moveTo(16,5);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
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