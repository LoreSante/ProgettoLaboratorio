cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp findpathTestFixtures.cpp MapRendererTests.cpp GameCharacterTest.cpp)
add_executable(projectTests ${TEST_SOURCE_FILES})
target_link_libraries(projectTests gtest gtest_main core)



set(SFML_BUILD_GRAPHICS, TRUE)
set(SFML_BUILD_WINDOW , TRUE)

find_package(SFML 2 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    target_link_libraries(projectTests core sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
endif()