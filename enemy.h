// enemy.h

#pragma once

#include"raylib.h"

class Enemy
{
    private:
        float hitPoints = 20;
        float x = 100;
        float y = 100;
        float speed = 1;
        float angle = 0;
        int attackDmg = 3;
        int attackTimer = 0;
        float attackRange = 40;
        bool alive = 1;

    public:

        Enemy(float,float);
        bool shouldAttack(int,int);
        bool continueAttack();
        void move(int,int);
        void attack();
        void draw();
        
        int getX();
        int getY();
        int getAttackRange();
        
        void takeDamage(int);
        Vector2 getPos();

        void kill();
        bool isAlive();
};
