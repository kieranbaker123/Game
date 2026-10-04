// player.h

#pragma once

#include<string>

class Player
{
private:
    float xpos = 50;
    float ypos = 50;
    float playerSpeed = 0;
    int playerSize = 10;

public:
    void playerUpdate(std::string);
    void move(char);
    int xPos();
    int yPos();
    void setx(int);
    void sety(int);
    void draw();
};
