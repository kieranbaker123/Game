// exit.h

#pragma once

class Exit
{
private:
    int x;
    int y;
    int width = 20;
    int height = 20;

    int aX;
    int aY;

    char side;

    bool _canReturn = 1;

public:

    Exit(int x, int y, int width, int height, char, int spawnx, int spawny);

    bool hasPlayer(int playerX, int playerY);
    
    void draw();
    
    int getaY();
    int getaX();

    // functions for making exit on opposite room 
    int getWidth();
    int getHeight();
    char getSide();
    int outExitX();
    int outExitY();
    bool canReturn();
    char getOppSide();
    int makeOppAx();
    int makeOppAy();
};
