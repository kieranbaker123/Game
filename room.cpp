// room.cpp
#include"configuration.h"
#include"room.h"
#include"raylib.h"

void Room::drawRoom()
{
int wallWidth = 10;
DrawRectangle( 0, 0, config::screenWidth, wallWidth, BLACK); // top roof
DrawRectangle( 0, 0, wallWidth, config::screenHeight, BLACK); // left wall
DrawRectangle(config::screenWidth - wallWidth, 0, wallWidth, config::screenHeight, BLACK); // right wall
DrawRectangle(0, config::screenHeight - wallWidth, config::screenWidth, wallWidth, BLACK); // bottom wall
}
