// main.cpp

#include "projectile.h"
#include "map.h"
#include "raylib.h"
#include "player.h"
#include "config.h"
#include "room.h"
#include <vector>
#include <string>

int main()
{
    int i,j,cd = 0;
    Map map;
    srand(time(NULL));
    Player player1;
    player1.setx(50);
    player1.sety(50);
    SetMousePosition( config::screenWidth / 2, config::screenHeight / 2 );
    std::vector<Projectile> projectiles;
    projectiles.reserve(1000);
    const char windowName[] = "Game";
    InitWindow(config::screenWidth, config::screenHeight, windowName );
    SetTargetFPS(config::FPS);
    char a;
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
        if ( IsKeyPressed(KEY_SPACE) && cd <= 0 )
            {
            cd = 10;
            projectiles.push_back( player1.fire());
            }
        player1.playerUpdate(player1.getMove());
        ClearBackground(map.getCurrentRoom()->getColor());
        j = projectiles.size();
        for ( i = 0; i < j; i++ )
        {
            projectiles[i].move();
            projectiles[i].draw();
            if ( projectiles[i].isAlive() == 0 )
            {
                projectiles.erase(projectiles.begin() + i);
                j--;
                i--;
            }
        }
        player1.draw();
        map.getCurrentRoom()->drawRoom();
        EndDrawing();
        cd--;
    }

    CloseWindow();

    return 0;
}


