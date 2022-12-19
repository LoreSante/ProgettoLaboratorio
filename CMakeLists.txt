cmake_minimum_required(VERSION 3.5)
project(ProgettoLaboratorio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES findpath.cpp findpath.h stlastar.h fsa.h Map.cpp Map.h MapRenderer.cpp MapRenderer.h Observer.h Subject.h GameCharacter.h GameCharacter.cpp CharacterRenderer.cpp CharacterRenderer.h)
add_executable(ProgettoLaboratorio main.cpp)
add_library(core ${SOURCE_FILES})
#target_link_libraries(ProgettoLaboratorio core) #questa istruzione viene eseguita dopo


set(SFML_BUILD_GRAPHICS, TRUE)
set(SFML_BUILD_WINDOW , TRUE)

find_package(SFML 2 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    target_link_libraries(ProgettoLaboratorio core sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
endif()
