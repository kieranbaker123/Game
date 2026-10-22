// ememy.cpp

#include "enemy.h"
#include"config.h"
#include <cmath>

void Enemy::move(int playerx, int playery)
{
    if ( attacking <= 0 )
    {
        int xDiff;
        int yDiff;
        xDiff = playerx - x;
        yDiff = playery - y;
        
        angle = std::atan2(yDiff, xDiff) * 180.0 / M_PI + 90;
        distance = std::sqrt( xDiff * xDiff + yDiff * yDiff);
        
        x += (float)xDiff / distance;
        y += (float)yDiff / distance;        
    }
}

bool shouldAttack(int playerx, int playery)
{
CheckCollisionCircles(Vector2 center1, config::playerSize, {x,y}, attackRange);

}

void Enemy::attack()
{
    attackTimer = 30;
}

void Enemy::draw()
{
    if ( attackTimer <= 10 || attackTimer >= 27)
    {
    // no attack
    }
    else if ( attackTimer <= 14 )
    {
    // attack 3
    }
    else if ( attackTimer <= 18 )
    {
    // attack 2
    }
    else if ( attackTimer <= 23 )
    {
    //attack 1
    }
    else if ( attackTime <= 26 )
    {
    // attack 0
    }
}

void Enemy::continueAttack()
{
    --attackTimer;
}
