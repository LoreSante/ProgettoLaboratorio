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
    ASSERT_EQ(map->getWorldMap(), renderer->getMap()->getWorldMap());

}
