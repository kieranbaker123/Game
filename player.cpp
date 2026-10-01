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

void Player::move(char a)
{
    switch(a)
    {
        case 'a':
        xpos -= 1;
        break;
        case 'd':
        xpos += 1;
        break;
        case 'w':
        ypos += 1;
        break;
        case 's':
        ypos -= 1;
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
