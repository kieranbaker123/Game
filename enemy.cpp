// ememy.cpp

#include"enemy.h"
#include"config.h"
#include"raylib.h"
#include"sprites.h"
#include <cmath>

Enemy::Enemy( float _x, float _y )
{
    x = _x;
    y = _y;
}

void Enemy::move(int playerx, int playery)
{
    if ( attackTimer <= 0 )
    {
        float xDiff = playerx - x;
        float yDiff = playery - y;
        
        angle = std::atan2(yDiff, xDiff) * 180.0 / M_PI - 90;
        float distance = std::sqrt( xDiff * xDiff + yDiff * yDiff);
        
        x += (float)xDiff / distance;
        y += (float)yDiff / distance;        
    }
}

bool Enemy::shouldAttack(int playerx, int playery)
{
bool a;
a = CheckCollisionCircles({(float)playerx,(float)playery}, config::playerSize + 2, {x,y}, attackRange);
return a;
}

void Enemy::attack()
{
    if ( attackTimer <= 0 )
    {
        attackTimer = 70;
    }
}

void Enemy::draw()
{
    if ( attackTimer <= 8 || attackTimer >= 49 || attackTimer >= 12 && attackTimer <= 16 )
    {
    DrawTexturePro(sprites.clubTroll, { 0, 0, (float)sprites.clubTroll.width, (float)sprites.clubTroll.height }, { x, y, 128, 128}, {64, 64}, angle, WHITE );
    }
    else if ( attackTimer <= 22 )
    {
    DrawTexturePro(sprites.clubTrollAttack[3], { 0, 0, (float)sprites.clubTrollAttack[3].width, (float)sprites.clubTrollAttack[3].height }, { x, y, 128, 128}, {64, 64}, angle, WHITE );
    }
    else if ( attackTimer <= 35 )
    {
    DrawTexturePro(sprites.clubTrollAttack[2], { 0, 0, (float)sprites.clubTrollAttack[2].width, (float)sprites.clubTrollAttack[2].height }, { x, y, 128, 128}, {64, 64}, angle, WHITE );
    }
    else if ( attackTimer <= 45 )
    {
    DrawTexturePro(sprites.clubTrollAttack[1], { 0, 0, (float)sprites.clubTrollAttack[1].width, (float)sprites.clubTrollAttack[1].height }, { x, y, 128, 128}, {64, 64}, angle, WHITE );
    }
    else if ( attackTimer <= 60 )
    {
    DrawTexturePro(sprites.clubTrollAttack[0], { 0, 0, (float)sprites.clubTrollAttack[0].width, (float)sprites.clubTrollAttack[0].height }, { x, y, 128, 128}, {64, 64}, angle, WHITE );
    }
}

void Enemy::continueAttack()
{
    --attackTimer;
}
