//
// Created by lolle21 on 02/02/22.
//

#ifndef PROGETTOLABORATORIO_FINDPATH_H
#define PROGETTOLABORATORIO_FINDPATH_H
class MapSearchNode
{
public:


    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py ) { x=px; y=py; }

    // map helper functions
    int GetMap( int x, int y )
    {
        if( x < 0 ||
            x >= MAP_WIDTH ||
            y < 0 ||
            y >= MAP_HEIGHT
                )
        {
            return 9;
        }

        return world_map[(y*MAP_WIDTH)+x];
    }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );

    void PrintNodeInfo();

    const int *getWorldMap() const {
        return world_map;
    }

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

    static const int getMapWidth() {
        return MAP_WIDTH;
    }

    static const int getMapHeight() {
        return MAP_HEIGHT;
    }

private:
    // the (x,y) positions of the node
    int x;
    int y;

    // Global data
    static const int MAP_WIDTH = 20;
    static const int MAP_HEIGHT = 20;

    // The world map  //TODO separare classe mappa e classe findpath
    int world_map[ MAP_WIDTH * MAP_HEIGHT ] =
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



};
#endif //PROGETTOLABORATORIO_FINDPATH_H
