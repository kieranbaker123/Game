// map.h

#pragma once

#include"room.h"
#include"config.h"
#include<vector>


class Map
{
private:
    std::vector<std::vector<Room*>> map;
    std::vector<Room> roomData;
    Room startRoom;
    Room* currentRoom;
    int roomsTraveled = 0;
    int currentRoomX;
    int currentRoomY;
    
public:
    
    Map();

    int getSpawnX(char,int);
    int getSpawnY(char,int);    
    Room generateRoom();
    void changeRoom(char);
    void checkRoom();
    Room* getCurrentRoom();    
};




