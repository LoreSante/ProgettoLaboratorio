//
// Created by lolle21 on 04/02/22.
//

#include "MapRenderer.h"

MapRenderer::MapRenderer(Map *map) {
    this->map=map;
}

void MapRenderer::renderMap(int length, int height) {

    mapTexture.create(length, height);

    sf::Image image;
    image.create(length, height, sf::Color(0, 0, 0));

    sf::Color plainColor=sf::Color(0, 168, 107); //green
    sf::Color unpassableWallColor=sf::Color(61, 43, 31); //brown
    //sf::Color lowHillColor=sf::Color(100,168,107);
    sf::Color mediumHillColor=sf::Color(100,168,54);
    //sf::Color highHillColor=sf::Color(100,168,0);
    //sf::Color lowMountainColor=sf::Color(200,168,107);
    sf::Color mediumMountainColor=sf::Color(200,168,54);
    //sf::Color highMountainColor=sf::Color(200,168,0);


    //si possono creare altri colori per altri costi nel percorso

    for (int i = 0; i < (map->getMapWidth()); i++) {
        for (int j = 0; j < (map->getMapHeight()); j++) {
            if (map->getValueOfSlot(i,j) == unpassableWall) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       unpassableWallColor);
                    }
                }
            } else if (map->getValueOfSlot(i,j) == plain) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       plainColor);
                    }
                }
            }else if (map->getValueOfSlot(i,j) == mediumHill) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       mediumHillColor);
                    }
                }
            }else if (map->getValueOfSlot(i,j) == mediumMountain) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       mediumMountainColor);
                    }
                }
            } // è possible aggiungere al metodo casi di livelli diversi e con colori diversi
        }
    }
    mapTexture.update(image);
    mapTexture.setSmooth(true);
    mapSprite.setTexture(mapTexture);

}

void MapRenderer::update(){
    int width=map->getMapWidth();
    int height=map->getMapHeight();
    this->renderMap(width, height);
}