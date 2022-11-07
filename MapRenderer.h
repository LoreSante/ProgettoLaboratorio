//
// Created by lolle21 on 04/02/22.
//

#ifndef PROGETTOLABORATORIO_MAPRENDERER_H
#define PROGETTOLABORATORIO_MAPRENDERER_H

#include "Map.h"
#include <SFML/Graphics.hpp>
#include "Observer.h"

class MapRenderer: public Observer {
public:
    MapRenderer(Map* map);

    void renderMap(int length, int height,sf::Sprite &sprite, sf::Texture &textureMap);
    //length e height sono riferiti alle dimensioni della texture. E' necessario passare i riferimenti di sprite e
    // texture per farli sopravvievere dopo l'uscita dal metodo
    void renderMap(int length, int height);

    Map* getMap(){
        return map;
    }

    void update();

    const sf::Sprite &getMapSprite() const {
        return mapSprite;
    }


private:
    Map* map;

    sf::Sprite mapSprite;
    sf::Texture mapTexture;

};


#endif //PROGETTOLABORATORIO_MAPRENDERER_H
