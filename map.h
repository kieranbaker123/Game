// map.h

#pragma once

#include"config.h"
#include<vector>

class Map
{
private:
    std::vector<std::vector<Room*>> map;
    Room startRoom;
    Room* currentRoom = &startRoom;
    int roomsTraveled;
    int bossRoom = rand() % 5 + 8;
    int finalBossRoom;
    int currentRoomX;
    int currentRoomY;

public:
    
    Map makeMap(int,int);

    Room* generateRoom(Exit entrance);
    void changeRoom(Exit);
    void checkRoom();

};




