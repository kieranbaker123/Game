// map.cpp

#include"map.h"
#include"room.h"


Map::Map()
    : startRoom(false, false, true, true),
        map(config::mapHeight, std::vector<Room*>(config::mapWidth, nullptr))
{
    currentRoomX = config::mapWidth / 2;
    currentRoomY = config::mapHeight / 2;
    roomData.push_back(startRoom);
    map[int(currentRoomY)][int(currentRoomX)] = &roomData[0];
    currentRoom = map[int(config::mapHeight/2)][int(config::mapWidth/2)];
}

Room Map::generateRoom()
{
    roomsTraveled += 1;
    // 0 = cannot make exit to ...
    // 2 = can make exit to ...
    // 1 = must make exit to ...
    int north;
    int south;
    int west;
    int east;

    if ( currentRoomX > 0 )
        {
        if ( map[currentRoomY][currentRoomX-1] == nullptr )
            {
            west = 2;
            }
        else if ( map[currentRoomY][currentRoomX-1]->hasExitEast() )
            {
            west = 1;
            }
        else
            {
            west = 0;
            }
        }
    else
        {
        west = 0;
        }
    if ( currentRoomY > 0 )
        {
        if ( map[currentRoomY-1][currentRoomX] == nullptr )
            {
            north = 2;
            }
        else if ( map[currentRoomY-1][currentRoomX]->hasExitSouth() )
            {
            west = 1;
            }
        else
            {
            west = 0;
            }
        }
    else
        {
        west = 0;
        }
    if ( currentRoomX < config::mapWidth )
        {
        if ( map[currentRoomY][currentRoomX+1] == nullptr )
            {
            west = 2;
            }
        else if ( map[currentRoomY][currentRoomX+1]->hasExitWest() )
            {
            west = 1;
            }
        else
            {
            west = 0;
            }
        }
    else
        {
        west = 0;
        }
    if ( currentRoomY > 0 )
        {
        if ( map[currentRoomY+1][currentRoomX] == nullptr )
            {
            north = 2;
            }
        else if ( map[currentRoomY+1][currentRoomX]->hasExitNorth() )
            {
            west = 1;
            }
        else
            {
            west = 0;
            }
        }
    else
        {
        west = 0;
        }

    if ( west == 2 )
        {
        west = (( rand() % 100 ) >= 20 );
        }
    if ( east == 2 )
        {
        east = (( rand() % 100 ) >= 20 );
        }
    if ( south == 2 )
        {
        south = (( rand() % 100 ) >= 20 );
        }
    if ( north == 2 )
        {
        north = (( rand() % 100 ) >= 20 );
        }

    Room room(north,south,east,west);
    return room;
}

void Map::changeRoom(char a)
{
    int y = currentRoomY;
    int x = currentRoomX; 
    switch (a)
        {
        case 'n':
            --currentRoomY;
            break;
        case 's':
            ++currentRoomY;
            break;
        case 'e':
            ++currentRoomX;
            break;
        case 'w':
            --currentRoomX;
            break;
        }
    
    if ( map[currentRoomY][currentRoomX] == nullptr )
        {
        roomData.push_back(generateRoom());
        map[currentRoomY][currentRoomX] = &roomData[roomData.size() - 1];
        }
    else 
        {
        currentRoom = map[currentRoomY][currentRoomX];
        }
}

Room* Map::getCurrentRoom()
{
return currentRoom;
}        
