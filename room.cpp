// room.cpp

#include"config.h"
#include"room.h"
#include"raylib.h"

Room::Room( bool north, bool south, bool east, bool west )
{
exitNorth = north;
exitSouth = south;
exitEast = east;
exitWest = west;
}

void Room::drawRoom()
{
DrawRectangle( 0, 0, config::screenWidth, config::wallWidth, BLACK); // top roof
DrawRectangle( 0, 0, config::wallWidth, config::screenHeight, BLACK); // left wall
DrawRectangle(config::screenWidth - config::wallWidth, 0, config::wallWidth, config::screenHeight, BLACK); // right wall
DrawRectangle(0, config::screenHeight - config::wallWidth, config::screenWidth, config::wallWidth, BLACK); // bottom wall
if ( exitNorth )
    {
    DrawRectangle( config::screenWidth / 2 - 30, 0, 60, config::wallWidth, YELLOW);
    }
if ( exitSouth )
    {
    DrawRectangle( config::screenWidth / 2 - 30, config::screenHeight - config::wallWidth, 60, config::wallWidth, YELLOW);
    }
if ( exitWest )
    {
    DrawRectangle( 0, config::screenHeight / 2 - 30, config::wallWidth, 60, YELLOW);
    }
if ( exitEast )
    {
    DrawRectangle( config::screenWidth - config::wallWidth, config::screenHeight / 2 - 30, config::wallWidth, 60, YELLOW);
    }
}

char Room::onExit(int x, int y)
{
    if ( x < 20 )
        {
        if ( y < config::screenHeight / 2 + 30 && y > config::screenHeight / 2 - 30 )
            {
            if ( exitWest )
                {
                return 'w';
                }
            }
        }
    if ( x > config::screenWidth - 20 )
        {
        if ( y < config::screenHeight / 2 + 30 && y > config::screenHeight / 2 - 30 )
            {
            if ( exitEast )
                {
                return 'e';
                }
            }
        }
    if ( x > config::screenWidth / 2 - 30 && x < config::screenWidth / 2 + 30 )
        {
        if ( y < 20 )
            {
            if ( exitNorth )
                {
                return 'n';
                }
            }
        if ( y > config::screenHeight - 20 )
            {
            if ( exitSouth )
                {
                return 's';
                }
            }
        }
return '\0';
}

bool Room::hasExitNorth()
{
return exitNorth;
}    
bool Room::hasExitSouth()
{
return exitSouth;
}
bool Room::hasExitEast()
{
return exitEast;
}
bool Room::hasExitWest()
{
return exitWest;
}

void Room::randColor()
{
    unsigned char a = rand() % 155 + 60;
    color = { a, a, a, 255 };
}

Color Room::getColor()
{
    return color;
}

bool Room::canMove(float x, float y, int size)
{
    const float w  = config::wallWidth;
    const float cx = config::screenWidth  / 2;
    const float cy = config::screenHeight / 2;
    const float gap = 30;   // half the door width

    bool inGapX = std::fabs(x - cx) <= gap - size;
    bool inGapY = std::fabs(y - cy) <= gap - size;

    bool westOk  = (x - size >= w) || (exitWest  && inGapY);
    bool eastOk  = (x + size <= config::screenWidth  - w) || (exitEast  && inGapY);
    bool northOk = (y - size >= w) || (exitNorth && inGapX);
    bool southOk = (y + size <= config::screenHeight - w) || (exitSouth && inGapX);

    return westOk && eastOk && northOk && southOk;
}
