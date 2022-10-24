//
// Created by lolle21 on 03/02/22.
//

#include "Map.h"

Map::Map(int width, int height) {
    this->width=width;
    this->height=height;
    world_map=new int[width*height];

    // fixme: decidere come riempire la mappa, probabilmente sarà necessario implementare la creazione da immagine
    // DEPRECATO - TROPPO COMPLESSO, TROVARE SOLUZIONE ALTERNATIVA

}

Map::Map(){
    width=20;
    height=20;
   // world_map=new int[width*height];
    world_map=new int[ width * height ]
            {

// 0001020304050607080910111213141516171819
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
                    1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
                    1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
                    1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
                    1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
                    1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
                    1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
                    1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
                    1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
                    1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
                    1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
                    1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
                    1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
                    1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
                    1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
                    1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
                    1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
                    1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
                    1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 19

            };
}


int Map::GetMap( int x, int y )
{
    if( x < 0 ||
        x >= width ||
        y < 0 ||
        y >= height
            )
    {
        return 9;
    }

    return world_map[(y*width)+x];
}

void Map::notifyObserver() const {  //todo


}

void Map::registerObserver (Observer *o){  //todo

}
void Map::removeObserver (Observer * o){  //todo

}