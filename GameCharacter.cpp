//
// Created by lolle21 on 16/02/22.
//

#include "GameCharacter.h"
#include "stlastar.h"
#include "findpath.h"

GameCharacter::GameCharacter(int x, int y) {
        this->x=x;
        this->y=y;
}

void GameCharacter::moveTo(int x, int y) {

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

        //RICERCA FINITA - INIZIO SPOSTAMENTO

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

} //todo implementa

void GameCharacter::removeObserver (Observer* o){

} //todo implementa

void GameCharacter::notifyObserver() const{

} //todo implementa
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