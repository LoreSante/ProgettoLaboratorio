//
// Created by lolle21 on 04/02/22.
//
#include "gtest/gtest.h"
#include "../MapRenderer.h"

TEST(MapRendererTest, ConstructorTest){
    Map* map=new Map;
    MapRenderer *renderer=new MapRenderer(map);
    ASSERT_EQ(20, renderer->getMap()->getMapHeight());
    ASSERT_EQ(20, renderer->getMap()->getMapWidth());
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            ASSERT_EQ(map->getValueOfSlot(i,j), renderer->getMap()->getValueOfSlot(i,j));
        }
    }
}
