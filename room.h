// room.h

#pragma once

#include"raylib.h"
#include<vector>

class Room
{
    private:
    // has exit on side
    bool exitNorth;
    bool exitSouth;
    bool exitEast;
    bool exitWest;
    Color color = WHITE;

    public:

    Room(bool north, bool south, bool east, bool west);
    
    void randColor();
    Color getColor();
    
    bool hasExitNorth();
    bool hasExitSouth();
    bool hasExitEast();
    bool hasExitWest();

    void drawRoom();
    char onExit(int,int);
};
