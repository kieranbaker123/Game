// main.cpp

#include "projectile.h"
#include "map.h"
#include "raylib.h"
#include "player.h"
#include "config.h"
#include "room.h"
#include "sprites.h"
#include <vector>
#include <string>

int main()
{
    InitWindow(config::screenWidth, config::screenHeight, "Game" );
    int QQ = 0;
    LoadSprites();
    int i,j,cd = 0;
    Map map;
    srand(time(NULL));
    Player player1;
    SetMousePosition( config::screenWidth / 2, config::screenHeight / 2 );
    std::vector<Projectile> projectiles;
    projectiles.reserve(1000);
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
        if ( IsKeyPressed(KEY_SPACE) && player1.getCD() <= 0 )
            {
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
        
        if ( IsKeyPressed(KEY_T) )
        {
            player1.arrowUpgrade();
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


