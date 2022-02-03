//
// Created by lolle21 on 02/02/22.
//

#ifndef PROGETTOLABORATORIO_FINDPATH_H
#define PROGETTOLABORATORIO_FINDPATH_H

#include <memory>
#include "stlastar.h"
#include "Map.h"
#include "fsa.h"

class MapSearchNode
{
public:

    MapSearchNode() {
        x = 0;
        y = 0;
        map= new Map();

    }

    MapSearchNode( int px, int py ) {
        x=px;
        y=py;
        map= new Map();

    }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();

    int getX() const {
        return x;
    }

    void setX(int x) {
        MapSearchNode::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        MapSearchNode::y = y;
    }

    Map *getMap() const {
        return map;
    }

    void setMap(Map* map){
        this->map=map;
    }

    int getMapHeight(); //restituisce l'altezza della mappa puntata da map
    int getMapWidth(); //restitusce la larghezza della mappa puntata da map





private:
    // the (x,y) positions of the node
    int x;
    int y;
    Map* map;



};
#endif //PROGETTOLABORATORIO_FINDPATH_H
