// map.h

#include"config.h"
#include<vector>

class Map
{
private:
    std::vector<std::vector<Room*>> map( config::mapHeight, std::vector<Room*>(config::mapWidth, nullptr));
    Room startRoom;
    Room* currentRoom = &startRoom;
    map[int(config::mapHeight/2)][int(config::mapWidth/2)] = startRoom;

public:
    Room generateRoom(Exit entrance, int requiredExits, int roomsExplored);
    void changeRoom(Exit);
    void checkRoom();

};




