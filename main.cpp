// main.cpp

#include <string>
#include "raylib.h"
#include "player.h"

std::string getMove();

int main()
{
    std::string move;
    Player player1;
    player1.setx(100);
    player1.sety(100);
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    constexpr char windowName[] = "Game";
    InitWindow(screenWidth, screenHeight, windowName );
    int i;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        move = getMove();
	    if ( move[0] == '1' ) {player1.move('w');}
        if ( move[1] == '1' ) {player1.move('a');}
        if ( move[2] == '1' ) {player1.move('s');}
        if ( move[3] == '1' ) {player1.move('d');}



        ClearBackground(GRAY);
        DrawRectangle( player1.xPos(), player1.yPos(), 100, 35, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

std::string getMove()
{
    bool w = IsKeyDown(KEY_W);
    bool a = IsKeyDown(KEY_A);
    bool s = IsKeyDown(KEY_S);
    bool d = IsKeyDown(KEY_D);
    std::string result = std::to_string(w) + std::to_string(a) + std::to_string(s) + std::to_string(d);
    return result;
}
