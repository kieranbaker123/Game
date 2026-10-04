// player.cpp

#include"player.h"
#include"config.h"
#include"raylib.h"

void Player::playerUpdate(std::string m)
{
    if ( m[0] == '1' ) {move('w');}
    if ( m[1] == '1' ) {move('a');}
    if ( m[2] == '1' ) {move('s');}
    if ( m[3] == '1' ) {move('d');}    
    draw();
}

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
            xpos -= ( playerSpeed * 0.2 + 2.5 ) * config::screenWidth / 800;
            }
        break;
        case 'd':
        if (xpos < config::screenWidth - playerSize)
            {
            xpos += ( playerSpeed * 0.2 + 2.5 ) * config::screenWidth / 800;
            }
        break;
        case 's':
        if ( ypos < config::screenHeight - playerSize)
            {
            ypos += ( playerSpeed * 0.2 + 2.5 ) * config::screenHeight / 600;
            }
        break;
        case 'w':
        if ( ypos > playerSize)
            {
            ypos -= ( playerSpeed * 0.2 + 2.5 ) * config::screenHeight / 600;
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
