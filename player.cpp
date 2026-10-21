// player.cpp

#include"player.h"
#include"projectile.h"
#include"config.h"
#include"raylib.h"
#include<cmath>

std::string Player::getMove()
{
    bool w = IsKeyDown(KEY_W);
    bool a = IsKeyDown(KEY_A);
    bool s = IsKeyDown(KEY_S);
    bool d = IsKeyDown(KEY_D);
    std::string result = std::to_string(w) + std::to_string(a) + std::to_string(s) + std::to_string(d);
    return result;
}

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
    DrawCircle(xPos(),yPos(),playerSize,RED); 
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
            xpos -= ( playerSpeed * 0.1 + 1 ) * config::baseSpeed;
            }
        break;
        case 'd':
        if (xpos < config::screenWidth - playerSize )
            {
            xpos += ( playerSpeed * 0.1 + 1 ) * config::baseSpeed;
            }
        break;
        case 's':
        if ( ypos < config::screenHeight - playerSize )
            {
            ypos += ( playerSpeed * 0.1 + 1 ) * config::baseSpeed;
            }
        break;
        case 'w':
        if ( ypos > playerSize )
            {
            ypos -= ( playerSpeed * 0.1 + 1 ) * config::baseSpeed;
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

Projectile Player::fire()
{
    currentCD = cooldown;    

    float xVelocity;
    float yVelocity;
    float xDiff;
    float yDiff;
    float distance;
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();    
    float angle;
    
    xDiff = mouseX - xpos;
    yDiff = mouseY - ypos;
    distance = std::sqrt( xDiff * xDiff + yDiff * yDiff);

    xVelocity = ( xDiff / distance ) * 3 * config::baseSpeed;
    yVelocity = ( yDiff / distance ) * 3 * config::baseSpeed;

    angle = std::atan2(yDiff, xDiff) * 180.0 / M_PI + 90;
 
    Projectile arrow(xpos,ypos,xVelocity,yVelocity,4,GOLD,angle);
    arrow.move();
    return arrow;
}

void Player::reduceCD()
{
--currentCD;
}

int Player::getCD()
{
return currentCD;
}
