//
// Created by lolle21 on 04/02/22.
//

#include "MapRenderer.h"

MapRenderer::MapRenderer(Map *map) {
    this->map=map;
}

void MapRenderer::renderMap(int length, int height) {
    //sf::RenderWindow window(sf::VideoMode(length, height), "Mappa di gioco");
    //sf::Texture textureMap;

    mapTexture.create(length, height);

    sf::Image image;
    image.create(length, height, sf::Color(0, 0, 0));

    for (int i = 0; i < (map->getMapWidth()); i++) {
        for (int j = 0; j < (map->getMapHeight()); j++) {
            if (map->getValueOfSlot(i,j) == unpassableWall) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       sf::Color(61, 43, 31));
                    }
                }
            } else if (map->getValueOfSlot(i,j) == plain) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       sf::Color(0, 168, 107));
                    }
                }
            } // fixme: è possible aggiungere al metodo casi livelli diversi e con colori diversi
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