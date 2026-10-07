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

    char side;

public:

    void initExit(int x, int y, int width, int height, char, int spawnx, int spawny);

    bool hasPlayer(int playerX, int playerY);
    
    void draw();
    
    int getaY();
    int getaX();

    char getSide();
};
