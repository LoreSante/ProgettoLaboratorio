//
// Created by lolle21 on 03/02/22.
//

#ifndef PROGETTOLABORATORIO_MAP_H
#define PROGETTOLABORATORIO_MAP_H
#include "Subject.h"
#include <list>
#include<vector>


class Map: public Subject {
public:

    Map(); //il costruttore di default costruisce la mappa sulla base di una matrice di default

    // TODO creare metdo per accedere al vettore
    int getValueOfSlot(int i, int j);

    int GetMap( int x, int y );

    void registerObserver (Observer *o) override;
    void removeObserver (Observer * o) override;
    void notifyObserver () const override;

    int getMapWidth() const {
        return width;
    }

    int getMapHeight() const {
        return height;
    }

//INCAPSULARE MEGLIO MAPPA CON UN VECTOR

private:



    //int *world_map;
    std::vector<int> world_map;
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
