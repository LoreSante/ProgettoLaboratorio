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
    //void renderMap(int length, int height,sf::Sprite &sprite, sf::Texture &textureMap);
    Map *map=new Map();
    MapRenderer *mapRenderer=new MapRenderer(map);

    GameCharacter* gameCharacter=new GameCharacter(0, 0);
    gameCharacter->moveTo(16,5);
    CharacterRenderer* characterRenderer=new CharacterRenderer(gameCharacter);


    sf::RenderWindow window(sf::VideoMode(720, 720), "Mappa di gioco bruttissima");
    sf::Sprite mapSprite;
    sf::Texture mapTexture;

    /*
    mapRenderer->renderMap(720,720, mapSprite,mapTexture);
    mapSprite.setTexture(mapTexture);
    */
    mapRenderer->renderMap(720,720);

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        //gameCharacter->moveTo(0,0);
        sf::Vector2i position=sf::Mouse::getPosition(window);
        cout<<"Mouse Position: ("<<position.x<<", "<<position.y<<")";
        window.draw(mapRenderer->getMapSprite());
        window.draw(characterRenderer->renderCharacter());
        window.display();


    }

    return 0;
}