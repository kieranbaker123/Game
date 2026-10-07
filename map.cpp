// map.cpp

#include"map.h"

Map Map::makeMap(int height, int width )
{
    currentRoomX = width / 2;
    currentRoomY = height / 2;
    map = ( height, std::vector<Room>( width, nullptr));
    map[int(currentRoomY)][int(currentRoomX)] = startRoom;
    currentRoom = &map[int(config::mapHeight/2)][int(config::mapWidth/2)];
    return map;
}

Room Map::generateRoom(Exit entrance);
{
    Room room;
    room.addExit(

}

void Map::changeRoom(Exit exit)
{
    char a;
    a = exit.getSide();
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

        int playerY = exit.getAy();
        int playerX = exit.getAx();
    
    if ( map[currentRoomY][currentRoomX] == nullptr )
        {
        map[currentRoomY][currentRoomX] = generateRoom(exit);
        }
    else 
        {
        currentroom = map[currentRoomY][currentRoomX];
        }        
