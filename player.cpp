// player.cpp

#include"player.h"

void Player::setx(int a)
{
    xpos = a;
}

void Player::sety(int a)
{
    ypos = a;
}

void Player::move(int a)
{
    switch(a)
    {
        case 'A':
        xpos -= 1;
        break;
        case 'D':
        xpos += 1;
        break;
        case 'W':
        ypos -= 1;
        break;
        case 'S':
        ypos += 1;
        break;
    }
}

int Player::xPos()
{
    return xpos;
}

int Player::yPos()
{
    return ypos;
}
