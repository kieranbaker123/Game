// projectile.h

#pragma once

#include"raylib.h"

class Projectile
{
private:
    float x;
    float y;
    float vx;
    float vy;
    float radius = 2; 
    bool alive = 1;
    Color color = BLACK;

public:
    Projectile( float x, float y, float vx, float vy, float radius, Color color );
    void move();
    void draw();
    void kill();
    bool isAlive();

};
