//
// Created by lolle21 on 03/02/22.
//
#include "gtest/gtest.h"
#include "../findpath.h"
#include "../Map.h"

class MapSearchNodeTest : public ::testing::Test{
protected:
    virtual void SetUp(){
        msn.setX(0);
        msn.setY(0);
        msn.setMap(new Map());

    }

    MapSearchNode msn;


};

TEST_F(MapSearchNodeTest, GoalDistanceEstimateTest) {
    MapSearchNode* nodeGoal= new MapSearchNode();
    ASSERT_EQ(0.0,msn.GoalDistanceEstimate(*nodeGoal));
    nodeGoal->setX(10);
    ASSERT_EQ(10.0,msn.GoalDistanceEstimate(*nodeGoal));
    nodeGoal->setY(10);
    ASSERT_EQ(20,msn.GoalDistanceEstimate(*nodeGoal));

}

