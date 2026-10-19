// map.cpp

#include"map.h"
#include"room.h"

Map::Map()
    : startRoom(false, false, true, true),
        map(config::mapHeight, std::vector<Room*>(config::mapWidth, nullptr))
{
    roomData.reserve(config::mapWidth * config::mapHeight);

    currentRoomX = config::mapWidth / 2;
    currentRoomY = config::mapHeight / 2;
    roomData.push_back(startRoom);
    map[int(currentRoomY)][int(currentRoomX)] = &roomData[0];
    currentRoom = map[int(config::mapHeight/2)][int(config::mapWidth/2)];
}

int Map::getSpawnX(char a, int x)
{
    switch(a)
    {
        case 'w':
            return ( config::screenWidth - 40 );
        case 'e':
            return 40;
        default:
            return x;
    }
}

int Map::getSpawnY(char a, int y)
{
    switch(a)
    {
        case 's':
            return 40;
        case 'n':
            return ( config::screenHeight - 40 );
        default:
            return y;
    }
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
            north = 1;
            }
        else
            {
            north = 0;
            }
        }
    else
        {
        north = 0;
        }
    if ( currentRoomX < config::mapWidth - 1 )
        {
        if ( map[currentRoomY][currentRoomX+1] == nullptr )
            {
            east = 2;
            }
        else if ( map[currentRoomY][currentRoomX+1]->hasExitWest() )
            {
            east = 1;
            }
        else
            {
            east = 0;
            }
        }
    else
        {
        east = 0;
        }
    if ( currentRoomY < config::mapHeight - 1 )
        {
        if ( map[currentRoomY+1][currentRoomX] == nullptr )
            {
            south = 2;
            }
        else if ( map[currentRoomY+1][currentRoomX]->hasExitNorth() )
            {
            south = 1;
            }
        else
            {
            south = 0;
            }
        }
    else
        {
        south = 0;
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
    room.randColor();
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
        currentRoom = map[currentRoomY][currentRoomX];
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
