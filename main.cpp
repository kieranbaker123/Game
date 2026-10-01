// main.cpp

#include "raylib.h"
#include "player.h"

int main()
{
    Player player1;
    player1.setx(100);
    player1.sety(100);
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    constexpr char windowName[] = "Dungeon Crawler";
    InitWindow(screenWidth, screenHeight, windowName );
    int i;
    int xpos;
    int ypos;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        i = GetKeyPressed();
        switch (i)
            {
            case 'a':
            case 'd':
            case 's':
            case 'w':
            player1.move(i);
            break;
            }
	ClearBackground(RAYWHITE);
        DrawRectangle( 100+ player1.xPos(), 100 +player1.yPos(), 100, 35, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
