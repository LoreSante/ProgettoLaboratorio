//
// Created by lolle21 on 07/11/22.
//

#include "gtest/gtest.h"
#include "../GameCharacter.h"

TEST(GameCharacterTest, ConstructorTest){
    GameCharacter* gameCharacter=new GameCharacter();
    ASSERT_EQ(0, gameCharacter->getX());
    ASSERT_EQ(0, gameCharacter->getY());

    GameCharacter* gameCharacter2=new GameCharacter(16,5);
    ASSERT_EQ(16, gameCharacter2->getX());
    ASSERT_EQ(5, gameCharacter2->getY());
}

TEST(GameCharacterTest, MoveToTest){
    GameCharacter* gameCharacter=new GameCharacter();

    gameCharacter->moveTo(0,10);
    ASSERT_EQ(0, gameCharacter->getX());
    ASSERT_EQ(10, gameCharacter->getY());

    gameCharacter->moveTo(16,5);
    ASSERT_EQ(16, gameCharacter->getX());
    ASSERT_EQ(5, gameCharacter->getY());

    gameCharacter->moveTo(0,0);
    ASSERT_EQ(0, gameCharacter->getX());
    ASSERT_EQ(0, gameCharacter->getY());

}