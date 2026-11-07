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
    float angleDeg;
    bool alive = 1;
    Color color = BLACK;
    int idx = 0;
    int damage = 3 + idx;

public:
    Projectile( float x, float y, float vx, float vy, float radius, Color color, float angle, int index );
    void move();
    void draw();
    void kill();
    bool isAlive();
    float getAngle();
    Vector2 getPos();
    int doDamage();

};
