//
// Created by lolle21 on 04/02/22.
//

#include "MapRenderer.h"

MapRenderer::MapRenderer(Map *map) {
    this->map=map;
}

void MapRenderer::renderMap(int length, int height,sf::Sprite &sprite, sf::Texture &textureMap) {

    textureMap.create(length, height);



    sf::Image image;
    image.create(length, height, sf::Color(0, 0, 0));

    for (int i = 0; i < (map->getMapWidth()); i++) {
        for (int j = 0; j < (map->getMapHeight()); j++) {
            if (map->getWorldMap()[i + j * (map->getMapWidth())] == 9) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       sf::Color(61, 43, 31));
                    }
                }
            } else if (map->getWorldMap()[i + j * map->getMapWidth()] == 1) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       sf::Color(0, 168, 107));
                    }
                }
            }
        }
    }
    textureMap.update(image);
    textureMap.setSmooth(true);
    sprite.setTexture(textureMap);

    /*


     */

}

void MapRenderer::renderMap(int length, int height) {
    //sf::RenderWindow window(sf::VideoMode(length, height), "Mappa di gioco");
    //sf::Texture textureMap;

    mapTexture.create(length, height);

    sf::Image image;
    image.create(length, height, sf::Color(0, 0, 0));

    for (int i = 0; i < (map->getMapWidth()); i++) {
        for (int j = 0; j < (map->getMapHeight()); j++) {
            if (map->getWorldMap()[i + j * (map->getMapWidth())] == 9) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       sf::Color(61, 43, 31));
                    }
                }
            } else if (map->getWorldMap()[i + j * map->getMapWidth()] == 1) {
                for (int y = 0; y < length / (map->getMapWidth()); y++) {
                    for (int k = 0; k < height / (map->getMapHeight()); k++) {
                        image.setPixel(i * length / map->getMapWidth() + y, j * height / (map->getMapHeight()) + k,
                                       sf::Color(0, 168, 107));
                    }
                }
            }
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