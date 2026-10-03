// exit.h

#pragma once

class Exit
{
private:
    int x;
    int y;
    int width = 60;
    int height = 20;

    int aX;
    int aY;

    int destinationRoom;

public:

    void initExit(int x, int y, int width, int height, int destinationRoom, int spawnx, int spawny);

    bool hasPlayer(int playerX, int playerY);
    int getDestination();
    
    void draw();
    
    int getaY();
    int getaX();
};
