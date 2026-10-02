// player.cpp

#include<string>
#include"player.h"
#include "configuration.h"
#include "raylib.h"

void Player::draw()
{
    DrawCircle(xPos(),yPos(),10,RED); 
    
}

void Player::setx(int a)
{
    xpos = a;
}

void Player::sety(int a)
{
    ypos = a;
}

void Player::move(char a)
{
    switch(a)
        {
        case 'a':
        if (xpos > playerSize)
            {
            xpos -= playerSpeed * 0.05 + 0.2;
            }
        break;
        case 'd':
        if (xpos < config::screenWidth - playerSize)
            {
            xpos += playerSpeed * 0.05 + 0.2;
            }
        break;
        case 's':
        if ( ypos < config::screenHeight - playerSize)
            {
            ypos += playerSpeed * 0.05 + 0.2;
            }
        break;
        case 'w':
        if ( ypos > playerSize)
            {
            ypos -= playerSpeed * 0.05 + 0.2;
            }
        break;
        }
}

int Player::xPos()
{
    return int(xpos);
}

int Player::yPos()
{
    return int(ypos);
}
