// room.h

#pragma once

#include<vector>
#include "exit.h"

class Room
{
    private:
    int roomID;
    std::vector<Exit> exits;

    public:
    void addExit( Exit& e );
    void drawRoom();
    int getID();
    void setID(int);
};
