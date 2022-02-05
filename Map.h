//
// Created by lolle21 on 03/02/22.
//

#ifndef PROGETTOLABORATORIO_MAP_H
#define PROGETTOLABORATORIO_MAP_H
#include "Subject.h"
#include <list>


class Map: public Subject {
public:

    Map(int width, int height);
    Map();

    const int *getWorldMap() const {
        return world_map;
    }

    int GetMap( int x, int y );

    virtual void registerObserver (Observer *o);
    virtual void removeObserver (Observer * o);
    virtual void notifyObserver () const;

    int getMapWidth() {
        return width;
    }

    int getMapHeight() {
        return height;
    }
/*  //vecchia versione dimensioni della mappa
    static const int MAP_WIDTH = 20;
    static const int MAP_HEIGHT = 20;
*/
private:

    int *world_map;
    int width;
    int height;
    std::list<Observer*> observers;

    // The world map

/*  //vecchia versione del world_map

    int world_map[ width * height ] =
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

*/


};


#endif //PROGETTOLABORATORIO_MAP_H
