// player.h

#pragma once

#include"config.h"
#include"projectile.h"
#include<string>

class Player
{
private:
    float xpos = 50;
    float ypos = 50;
    float playerSpeed = 0;
    int attackSpeed = 0;
    int playerSize = 10 * config::screenWidth / 800;
    int cooldown = 12 - attackSpeed;
    int currentCD = 0;

public:
    void playerUpdate(std::string);
    void move(char);
    int xPos();
    int yPos();
    void setx(int);
    void sety(int);
    void draw();
    std::string getMove();
    Projectile fire();
    void reduceCD();    
    int getCD();

};
