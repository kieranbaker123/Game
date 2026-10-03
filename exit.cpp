//exit.cpp

#include "exit.h"
#include "raylib.h"

void Exit::exit(int x, int y, int width, int height, int destinationRoom)
    {
    
    }

bool Exit::hasPlayer(int playerX, int playerY)
    {
    if (playerX >= x && playerX <= x + width) 
        {
        if (playerY >= y && playerY <= y + height)
            {
            return 1;
            }
        }
    return 0;
    }

int Exit::getDestination()
    {
    return destinationRoom;
    }

void Exit::draw()
    {
    DrawRectangle( x, y, width, height, YELLOW );
    }
