// main.cpp

#include "map.h"
#include "raylib.h"
#include "player.h"
#include "config.h"
#include "room.h"
#include <vector>
#include <string>

int main()
{
    Map map;
    srand(time(NULL));
    Player player1;
    player1.setx(50);
    player1.sety(50);
    const char windowName[] = "Game";
    InitWindow(config::screenWidth, config::screenHeight, windowName );
    SetTargetFPS(60);
    char a;
    int i;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        a = map.getCurrentRoom()->onExit(player1.xPos() ,player1.yPos());
        if ( a != '\0' )
            {
            map.changeRoom(a);            
            player1.setx(500);
            player1.sety(500);
            }
        i = map.getx();
        player1.playerUpdate(player1.getMove());
        ClearBackground(map.getCurrentRoom()->getColor());
        player1.draw();
        map.getCurrentRoom()->drawRoom();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

