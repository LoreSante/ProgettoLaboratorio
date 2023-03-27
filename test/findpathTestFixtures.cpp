//
// Created by lolle21 on 03/02/22.
//
#include "gtest/gtest.h"
#include "../findpath.h"
#include "../Map.h"
#include <vector>

class MapSearchNodeTest : public ::testing::Test{
protected:
    virtual void SetUp(){
        msn.setX(0);
        msn.setY(0);
        msn.setMap(new Map());

        unwalkableMapVector={1,9,9,9,9,9,9,9,1};
        unwalkableMapMsn.setX(0);
        unwalkableMapMsn.setY(0);
        unwalkableMapMsn.setMap(new Map(3,3,unwalkableMapVector));

        unusualMapVector={2,2,2,3,2,2,2,2,1,1,
                          2,2,2,3,2,2,2,2,1,1,
                          2,2,2,3,2,3,3,3,2,2,
                          2,2,2,3,2,3,3,3,2,2,
                          1,1,2,3,3,4,3,3,2,2,
                          1,1,2,3,3,5,4,4,2,2,
                          1,1,2,2,2,5,4,3,2,2,
                          2,3,3,2,2,4,4,3,2,2,
                          2,4,3,2,2,4,4,3,2,2,
                          2,4,3,1,1,2,2,2,1,1,
                          2,2,2,1,1,2,2,2,1,1};
        unusualMapMsn.setX(0);
        unusualMapMsn.setY(0);
        unusualMapMsn.setMap(new Map(10,11,unusualMapVector));

    }

    MapSearchNode msn;

    std::vector<int> unwalkableMapVector;
    MapSearchNode unwalkableMapMsn;

    std::vector<int> unusualMapVector;
    MapSearchNode unusualMapMsn;


};

TEST_F(MapSearchNodeTest, GoalDistanceEstimateTest) {
    MapSearchNode* nodeGoal= new MapSearchNode();
    ASSERT_EQ(0.0,msn.GoalDistanceEstimate(*nodeGoal));
    nodeGoal->setX(10);
    ASSERT_EQ(10.0,msn.GoalDistanceEstimate(*nodeGoal));
    nodeGoal->setY(10);
    ASSERT_EQ(20,msn.GoalDistanceEstimate(*nodeGoal));
    nodeGoal->setMap(new Map(10,11,unusualMapVector));
    ASSERT_EQ(20,msn.GoalDistanceEstimate(*nodeGoal));

}

TEST_F(MapSearchNodeTest, AstarSearchSearchStepTest1){
    AStarSearch<MapSearchNode> aStarSearch;
    unsigned int searchState;

    MapSearchNode nodeStart;
    nodeStart.setX(0);
    nodeStart.setY(0);

    MapSearchNode nodeEnd;
    nodeEnd.setX(3);
    nodeEnd.setY(2);

    aStarSearch.SetStartAndGoalStates(nodeStart, nodeEnd);

    do
    {
        searchState = aStarSearch.SearchStep();
    }
    while( searchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );
    ASSERT_EQ(AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED,searchState);

}

TEST_F(MapSearchNodeTest, AstarSearchSearchStepTest2){
    AStarSearch<MapSearchNode> aStarSearch;
    unsigned int searchState;
    Map* map= new Map(3,3,unwalkableMapVector);

    MapSearchNode nodeStart;
    nodeStart.setX(0);
    nodeStart.setY(0);
    nodeStart.setMap(map);

    MapSearchNode nodeEnd;
    nodeEnd.setX(2);
    nodeEnd.setY(2);
    nodeStart.setMap(map);

    aStarSearch.SetStartAndGoalStates(nodeStart, nodeEnd);

    do
    {
        searchState = aStarSearch.SearchStep();
    }
    while( searchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

    ASSERT_EQ(AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED,searchState); //la mappa è un percorso chiuso

}

TEST_F(MapSearchNodeTest, AstarSearchSearchStepTest3){
    AStarSearch<MapSearchNode> aStarSearch;
    unsigned int searchState;
    Map* map= new Map(10,11,unusualMapVector);

    MapSearchNode nodeStart;
    nodeStart.setX(0);
    nodeStart.setY(0);
    nodeStart.setMap(map);

    MapSearchNode nodeEnd;
    nodeEnd.setX(6);
    nodeEnd.setY(8);
    nodeStart.setMap(map);

    aStarSearch.SetStartAndGoalStates(nodeStart, nodeEnd);

    do
    {
        searchState = aStarSearch.SearchStep();
    }
    while( searchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );
    ASSERT_EQ(AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED,searchState);

}


//inserire test con mappa piu complessa
//inserire test con percorso chiuso