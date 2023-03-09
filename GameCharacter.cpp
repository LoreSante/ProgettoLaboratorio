//
// Created by lolle21 on 16/02/22.
//

#include "GameCharacter.h"

#include "CharacterRenderer.h"


GameCharacter::GameCharacter(int x, int y) {
        this->x=x;
        this->y=y;
        gameCharacterAStarSearch=new AStarSearch<MapSearchNode>;
        SearchState=AStarSearch<MapSearchNode>::SEARCH_STATE_NOT_INITIALISED;
}

void GameCharacter::setStarAndGoal(int x, int y) {
    MapSearchNode nodeStart;
    nodeStart.setX(this->x);
    nodeStart.setY(this->y);

    // Define the goal state
    MapSearchNode nodeEnd;
    nodeEnd.setX(x);
    nodeEnd.setY(y);

    // Set Start and goal states
        gameCharacterAStarSearch->SetStartAndGoalStates(nodeStart, nodeEnd);

}

bool GameCharacter::isArrivedTo(int x, int y) {
    bool arrivedToGoalState;
    if(this->x == x && this->y == y){
        arrivedToGoalState=true;
        gameCharacterAStarSearch->CancelSearch();
        gameCharacterAStarSearch->FreeSolutionNodes();
    }
    else{
        arrivedToGoalState=false;
    }
    return arrivedToGoalState;
}

bool GameCharacter::searchPath() {
        do
        {
            SearchState = gameCharacterAStarSearch->SearchStep();
        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );
        bool state=false;
        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED ) {
            cout << "Search found goal state\n";
            state=true;
            gameCharacterAStarSearch->FreeSolutionNodes();

        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ){
            cout << "Search terminated. Did not find goal state\n";

        }
        return state;
}

void GameCharacter::doStep(){

        if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {

            MapSearchNode *node = gameCharacterAStarSearch->GetSolutionStart();

            node->PrintNodeInfo();

            node = gameCharacterAStarSearch->GetSolutionNext();

            if (node) {
                this->setPosition(node->getX(), node->getY());

                this->notifyObserver();

                node->PrintNodeInfo();

            }

        }

}


void GameCharacter::moveTo(int x, int y) { //unused

    AStarSearch<MapSearchNode> aStarSearch;
    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;

    while (SearchCount < NumSearches) {
        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.setX(this->x);
        nodeStart.setY(this->y);

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.setX(x);
        nodeEnd.setY(y);

        // Set Start and goal states
        aStarSearch.SetStartAndGoalStates(nodeStart, nodeEnd);


        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do
        {
            SearchState = aStarSearch.SearchStep();
            SearchSteps++;
        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

        //SEARCH END - START WALKING

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED ) {
            cout << "Search found goal state\n";

            MapSearchNode *node = aStarSearch.GetSolutionStart();

            int steps = 0;

            node->PrintNodeInfo();
            for( ;; )
            {
                node = aStarSearch.GetSolutionNext();

                if( !node )
                {
                    break;
                }
                this->setPosition(node->getX(),node->getY());

                this->notifyObserver();

                node->PrintNodeInfo();
                steps ++;

            };

            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            aStarSearch.FreeSolutionNodes();
        }

        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cout << "Search terminated. Did not find goal state\n";

        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount ++;

        aStarSearch.EnsureMemoryFreed();
    }
}

void GameCharacter::registerObserver (Observer* o){
    renderers.push_back(o);
}

void GameCharacter::removeObserver (Observer* o){
    renderers.remove(o);
}

void GameCharacter::notifyObserver() const{
    for(auto it=renderers.begin(); it!=renderers.end(); it++){
        (*it)->update();
    }

}
int GameCharacter::getX() const {
    return x;
}

int GameCharacter::getY() const {
    return y;
}

void GameCharacter::setPosition(int x, int y) {
    this->x=x;
    this->y=y;
}

const list<Observer *> &GameCharacter::getRenderers() const {
    return renderers;
}
