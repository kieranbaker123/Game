// main.cpp

#include "raylib.h"
#include "player.h"

char getInput();

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
    while (!WindowShouldClose())
    {
        BeginDrawing();
        player1.move(getInput());
	    ClearBackground(RAYGRAY);
        DrawRectangle( player1.xPos(), player1.yPos(), 100, 35, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

char getInput()
{
    bool w = IsKeyDown(KEY_W)
    bool a = IsKeyDown(KEY_A)
    bool s = IsKeyDown(KEY_S)
    bool d = IsKeyDown(KEY_D) 
}
