// player.cpp

#include<string>
#include"player.h"
#include "configuration.h"

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
        if (xpos > 0)
            {
            xpos -= 0.5;
            }
        break;
        case 'd':
        if (xpos < config::screenWidth )
            {
            xpos += 0.5;
            }
        break;
        case 's':
        if ( ypos < config::screenHeight )
            {
            ypos += 0.5;
            }
        break;
        case 'w':
        if ( ypos > 0 )
            {
            ypos -= 0.5;
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
