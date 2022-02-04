//
// Created by lolle21 on 04/02/22.
//

#ifndef PROGETTOLABORATORIO_MAPRENDERER_H
#define PROGETTOLABORATORIO_MAPRENDERER_H

#include "Map.h"
#include <SFML/Graphics.hpp>

class MapRenderer {
public:
    MapRenderer(Map *map):map(map){}


    void renderMap(int length, int height,sf::Sprite &sprite, sf::Texture &textureMap);
    //length e height sono riferiti alledimensioni della texture. E' necessario passare i riferimenti di sprite e
    // texture per farli sopravvievere dopo l'uscita dal metodo


    Map* getMap(){
        return map;
    }


private:
    Map* map;



};


#endif //PROGETTOLABORATORIO_MAPRENDERER_H
