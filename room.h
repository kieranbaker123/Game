// room.h

#pragma once

#include"raylib.h"
#include<vector>
#include "exit.h"

class Room
{
    private:
    int roomID;
    std::vector<Exit> exits;

    public:
    Color color = WHITE;
    void addExit( Exit& e );
    void drawRoom();
    int getID();
    void setID(int);
    std::vector<Exit> getExits();

};
