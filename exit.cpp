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

Exit::Exit(int xLocation, int yLocation, int width1, int height1, char s, int spawnX, int spawnY)
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

int Exit::outExitX()
    {
    int outx;
    switch (side)
        {
        case 'n':
        case 's':
        return x;
        case 'e':
        return 0;
        case 'w';
        outx = config::screenWidth - width;
        return outx;
        }
    }

int Exit::outExitY()
    {
    int outy;
    switch (side)
        {
        case 'e':
        case 'w':
        return y;
        case 's':
        return 0;
        case 'n';
        outy = config::screenHeight - height;
        return outy;
        }
    }

bool Exit::canReturn()
{
    return _canReturn;
}

int Exit::getWidth()
{
    return width;
}

int Exit::getHeight()
{
    return height;
}

char Exit::getOppSide()
{
    switch (side)
        {
        case 'n':
        return 's';
        case 's':
        return 'n';
        case 'e':
        return 'w';
        case 'w':
        return 'e';
        }
}

int Exit::makeOppAx()
{
    switch (side)
        {
        case 'n':
        case 's':
        return aX;        
        case 'w':
        return ( x + 20 + width);
        case 'e':
        return ( x - 20 - width );
        }
}

int Exit::makeOppAy()
{
    switch (side)
        {
        case 'w':
        case 'e':
        return aY;
        case 'n':
        return ( x + 20 + height);
        case 's':
        return ( x - 20 - height);
        }
}
