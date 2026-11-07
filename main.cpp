// main.cpp

#include "projectile.h"
#include "map.h"
#include "raylib.h"
#include "player.h"
#include "config.h"
#include "room.h"
#include "sprites.h"
#include "enemy.h"
#include <vector>
#include <string>
#include<iostream>
#include<ctime>
#include<cstdlib>

int main()
{
    InitWindow(config::screenWidth, config::screenHeight, "Game" );
    bool enemyAttack;
    LoadSprites();
    int i,j;
    Map map;
    srand(time(NULL));
    Player player1;
    SetMousePosition( config::screenWidth / 2, config::screenHeight / 2 );
    std::vector<Projectile> projectiles;
    projectiles.reserve(1000);
    std::vector<Enemy> enemies;
    enemies.reserve(100);
    SetTargetFPS(config::FPS);
    char a;
    enemies.push_back(Enemy(100,400));
    enemies.push_back(Enemy(800,300));
    enemies.push_back(Enemy(400,200));

    while (!WindowShouldClose())
    {
        BeginDrawing();
        a = map.getCurrentRoom()->onExit(player1.xPos() ,player1.yPos());        
        if ( a != '\0' )
        {
            map.changeRoom(a);            
            player1.setx(map.getSpawnX(a, player1.xPos()));
            player1.sety(map.getSpawnY(a, player1.yPos()));
            projectiles.clear();
        }
        if ( IsKeyPressed(KEY_SPACE) && player1.getCD() <= 0 )
            {
            projectiles.push_back( player1.fire());
            }
        player1.playerUpdate(player1.getMove(), map.getCurrentRoom());
        ClearBackground(map.getCurrentRoom()->getColor());
        j = projectiles.size();
        for ( i = 0; i < j; i++ )
        {
            projectiles[i].move();
            if ( projectiles[i].isAlive() == 0 )
            {
                projectiles.erase(projectiles.begin() + i);
                j--;
                i--;
            }
            else
            {
                projectiles[i].draw();
            }
        }
        
        for ( i = 0; i < enemies.size(); i++ )
        {
            if ( enemies[i].shouldAttack(player1.xPos(),player1.yPos()) == 1 )
            {
                enemies[i].attack();
            }
            enemies[i].move(player1.xPos(),player1.yPos());
            for ( j = 0; j < projectiles.size(); j++ )
            {
                if ( CheckCollisionCircles( enemies[i].getPos(), 24, projectiles[j].getPos(), config::arrowWid) )
                {
                    enemies[i].takeDamage(projectiles[j].doDamage());
                    projectiles.erase(projectiles.begin() + j);
                    j--;
                }
            }            
            if ( enemies[i].continueAttack() )
            {
                player1.isHit(enemies[i].getPos(),enemies[i].getAttackRange());
            }
            if ( !enemies[i].isAlive() )
            {
                enemies.erase(enemies.begin() + i);
            }
            enemies[i].draw();
        }

        map.getCurrentRoom()->drawRoom();
        player1.draw();

        player1.reduceCD();
        EndDrawing();
    }
    
    UnloadSprites();
    CloseWindow();

    return 0;
}


