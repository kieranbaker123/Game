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
    Exit exit1;
    Exit exit2;
    // 0 = cannot make exit to ...
    // 1 = can make exit to ...
    // 2 = must make exit to ...
    // 3 = must link exit to ...
    int up;
    int down;
    int left;
    int right;
    vector <Exit> temp;
    int i;
    exit1.initExit(entrance.outExitX(), entrance.outExitY(), entrance.getHeight, entrance.getWidth, entrance.getOppSide(), entrance.makeOppAx(), entrance.makeOppAy()); 
    room.addExit(exit1);
    if ( entrance.getSide() != 'n' && currentRoomY != 0 )
        {
        if ( map[currentRoomY-1][currentRoomX] != nullptr )
            {
            up = 1;
            }
        else
            {
            temp = map[currentRoomY-1][currentRoomX].getExits();
            for ( i = 0; i < temp.size(); i++ )
                {
                exit2 = temp[i];
                if ( exit2.getSide == 's' )
                    {
                    up = 3;
                    }
                }
            if ( up != 3 )
                {
                up = 0;
                }
            }
        }
    else
        {
        if ( currentRoomY != 0 )
            {
            up = 3;
            }
        else 
            {
            up = 0;
            }
        }
    if ( entrance.getSide() != 's' )
        {
        if ( map[currentRoomY+1][currentRoomX] != nullptr )
            {
            down = 1;
            }
        }
    if ( entrance.getSide() != 'w' )
        {
        if ( map[currentRoomY][currentRoomX-1] != nullptr )
            {
            left = 1;
            }
        }
    if ( entrance.getSide() != 'n' )
        {
        if ( map[currentRoomY-1][currentRoomX] != nullptr )
            {
            right = 1;
            }
        }
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
