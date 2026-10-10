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

    public:

    Room(bool north, bool south, bool east, bool west);
    
    bool hasExitNorth();
    bool hasExitSouth();
    bool hasExitEast();
    bool hasExitWest();

    Color color = WHITE;
    void drawRoom();
    char onExit(int,int);
};
