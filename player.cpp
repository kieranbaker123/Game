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

void Player::playerUpdate(std::string m, Room* room)
{
    if ( m[0] == '1' ) move('w', room);
    if ( m[1] == '1' ) move('a', room);
    if ( m[2] == '1' ) move('s', room);
    if ( m[3] == '1' ) move('d', room);
}

void Player::move(char a, Room* room)
{
    float step = ( playerSpeed * 0.1 + 1 ) * config::baseSpeed;
    float nx = xpos;
    float ny = ypos;

    switch ( a )
    {
        case 'a': nx -= step; break;
        case 'd': nx += step; break;
        case 'w': ny -= step; break;
        case 's': ny += step; break;
    }

    if ( room->canMove(nx, ny, playerSize) )
    {
        xpos = nx;
        ypos = ny;
    }
}

void Player::draw()
{
    DrawCircle(xPos(),yPos(),playerSize,color); 
}

void Player::setx(int a)
{
    xpos = a;
}

void Player::sety(int a)
{
    ypos = a;
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
 
    Projectile arrow(xpos,ypos,xVelocity,yVelocity,4,GOLD,angle,arrowType);
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

void Player::arrowUpgrade()
{
    if ( arrowType < 2 )
    {
    ++arrowType;
    }
}

void Player::isHit(Vector2 enemyCords, int enemyRange)
{
    Vector2 playerCords = {xpos,ypos};
    bool a = CheckCollisionCircles(playerCords, config::playerSize, enemyCords, enemyRange);
    if ( a )
    {
        color = ORANGE;
    }
}
