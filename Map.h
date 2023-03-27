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
    Map(int w, int h, std::vector<int> world_map):width(w),height(h),world_map(world_map){}

    int getValueOfSlot(int i, int j);

    int GetMap( int x, int y ); //utile in fase di test

    void registerObserver (Observer *o) override;
    void removeObserver (Observer * o) override;
    void notifyObserver () const override;

    int getMapWidth() const {
        return width;
    }

    int getMapHeight() const {
        return height;
    }

private:
    std::vector<int> world_map;
    int width;
    int height;
    std::list<Observer*> observers;

};


#endif //PROGETTOLABORATORIO_MAP_H
