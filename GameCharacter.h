//
// Created by lolle21 on 05/02/22.
//

#ifndef PROGETTOLABORATORIO_GAMECHARACTER_H
#define PROGETTOLABORATORIO_GAMECHARACTER_H

#include "Subject.h"
#include "stlastar.h"
#include "findpath.h"
#include <list>

class GameCharacter: public Subject {
public:

    GameCharacter(int x=0, int y=0);

    void moveTo(int x, int y);
    void setStarAndGoal(int x, int y);
    bool searchPath();
    void doStep();
    bool isArrivedTo(int x, int y);

    void registerObserver (Observer *o) override;
    void removeObserver (Observer * o) override;
    void notifyObserver () const override;

    int getX() const;
    int getY() const;

    void setPosition(int x, int y);

    const std::list<Observer *> &getRenderers() const;

private:
    int x;
    int y;
    std::list<Observer*> renderers;
    AStarSearch<MapSearchNode>* gameCharacterAStarSearch;
    unsigned int SearchState;



};


#endif //PROGETTOLABORATORIO_GAMECHARACTER_H
