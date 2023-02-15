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
        arrivedToGoalState=0;
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
    //else
        //gameCharacterAStarSearch->FreeSolutionNodes();
}

bool GameCharacter::isArrivedTo(int x, int y) {
    if(this->x == x && this->y == y){
        this->arrivedToGoalState=true;
    }
    else{
        this->arrivedToGoalState=false;
    }
    return this->arrivedToGoalState;
}

void GameCharacter::searchPath() {
    if(!arrivedToGoalState){
        do
        {
            SearchState = gameCharacterAStarSearch->SearchStep();
        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );
        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED ) {
            cout << "Search found goal state\n";
        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ){
            cout << "Search terminated. Did not find goal state\n";
        }
    }
}

void GameCharacter::doStep(){
    if(!arrivedToGoalState) {
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

    /*
        CharacterRenderer* characterRenderer;
        characterRenderer=dynamic_cast<CharacterRenderer*> (o);
        if(characterRenderer){
            renderers.push_back(characterRenderer);
        }
        //todo Gestisci le eccezioni (se non è un characterRenderer lancia l'eccezione)
        /*
         * else{
         *  lancia eccezione
         * }
         */

}

void GameCharacter::removeObserver (Observer* o){
    renderers.remove(o);

    /*
    CharacterRenderer* characterRenderer;
    characterRenderer=dynamic_cast<CharacterRenderer*> (o);
    if(characterRenderer){
        renderers.remove(characterRenderer);
    }
    //todo Gestisci le eccezioni (se non è un characterRenderer lancia l'eccezione)
    /*
     * else{
     *  lancia eccezione
     * }
     */
}

void GameCharacter::notifyObserver() const{
    for(auto it=renderers.begin(); it!=renderers.end(); it++){
        (*it)->update();
    }

} //todo verificane il funzionamento
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
