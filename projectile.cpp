// projectile.cpp

#include"projectile.h"
#include"config.h"
#include"raylib.h"

Projectile::Projectile( float _x, float _y, float _vx, float _vy, float _radius, Color _color, float _angle )
{
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    radius = _radius;
    color = _color;   
    angleDeg = _angle;
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

float Projectile::getAngle()
{
    return angleDeg;
}
