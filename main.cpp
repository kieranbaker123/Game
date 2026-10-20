// main.cpp

#include "projectile.h"
#include "map.h"
#include "raylib.h"
#include "player.h"
#include "config.h"
#include "room.h"
#include <vector>
#include <string>

struct images
{
    Texture2D arrow;
} images;

int main()
{
    InitWindow(config::screenWidth, config::screenHeight, "Game" );
    int QQ = 0;
    images.arrow = LoadTexture("arrow.png");
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
        QQ++;
        if ( QQ >= 360 )
        {
            QQ = 0;
        }
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

        player1.draw();
        map.getCurrentRoom()->drawRoom();

        DrawTexturePro(images.arrow, { 0, 0, (float)images.arrow.width, (float)images.arrow.height }, { 200, 200, 100, 100 }, {50, 50}, QQ, WHITE );

        player1.reduceCD();
        EndDrawing();
    }
    
    UnloadTexture(images.arrow);
    CloseWindow();

    return 0;
}


