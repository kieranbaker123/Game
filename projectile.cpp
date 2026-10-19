// projectile.cpp

#include"projectile.h"
#include"config.h"
#include"raylib.h"

Projectile::Projectile( float ax, float ay, float avx, float avy )
{
    x = ax;
    y = ay;
    vx = avx;
    vy = avy;
}

void Projectile::move()
{
    x += vx;
    y += vy;
    if ( x < 0 || x > config::screenWidth || y < 0 || y > config::screenHeight )
    {
        kill();
    }
}

void Projectile::draw()
{
    if ( alive )
    {
        DrawCircle( x, y, radius, color);
    }
}

void Projectile::kill()
{
    alive = 0;
}

bool Projectile::isAlive()
{
    return alive;
}
