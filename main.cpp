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
    int i;
    int j;
    Map map;
    srand(time(NULL));
    Player player1;
    player1.setx(50);
    player1.sety(50);
    std::vector<Projectile> projectiles;
    projectiles.reserve(1000);
    const char windowName[] = "Game";
    InitWindow(config::screenWidth, config::screenHeight, windowName );
    SetTargetFPS(60);
    char a;
    Projectile proj(300,300,1,1);
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
        projectiles.push_back( Projectile(player1.xPos(), player1.yPos(), rand() % 5 - 2, rand() % 5 - 2 ));
        player1.playerUpdate(player1.getMove());
        ClearBackground(map.getCurrentRoom()->getColor());
        j = projectiles.size();
        for ( i = 0; i < j - 1; i++ )
        {
            projectiles[i].move();
            projectiles[i].draw();
            if ( projectiles[i].isAlive() == 0 )
            {
                projectiles.erase(projectiles.begin() + i);
                j--;
            }
        }
        player1.draw();
        map.getCurrentRoom()->drawRoom();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}


