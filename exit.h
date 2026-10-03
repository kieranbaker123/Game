// exit.h

#pragma once

class Exit
{
private:
    int x = 450;
    int y = 450;
    int width = 20;
    int height = 20;

    int destinationRoom = 2;

public:
    void exit(int x, int y, int width, int height, int destinationRoom);

    bool hasPlayer(int playerX, int playerY);
    int getDestination();
    
    void draw();
};
