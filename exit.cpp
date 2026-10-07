//exit.cpp

#include "exit.h"
#include "raylib.h"

int Exit::getaX()
    {
    return aX;
    }

int Exit::getaY()
    {
    return aY;
    }

void Exit::initExit(int xLocation, int yLocation, int width1, int height1, char s, int spawnX, int spawnY)
    {
    x = xLocation;
    y = yLocation;
    width = width1;
    height = height1;
    aX = spawnX;
    aY = spawnY;
    side = s;
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

void Exit::draw()
    {
    DrawRectangle( x, y, width, height, YELLOW );
    }

char Exit::getSide()
{
return side;
}
