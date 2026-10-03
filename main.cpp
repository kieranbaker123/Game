// main.cpp

#include <string>
#include "raylib.h"
#include "player.h"
#include "configuration.h"
#include "room.h"


std::string getMove();

int main()
{
    std::string move;
    Player player1;
    Room room1;
    Room room2;
    room1.setID(1);
    room2.setID(2);
    room2.color = GRAY;
    Exit exit1;
    room1.addExit( exit1 );
    player1.setx(50);
    player1.sety(50);
    constexpr char windowName[] = "Game";
    InitWindow(config::screenWidth, config::screenHeight, windowName );
    SetTargetFPS(60);
    Room* currentRoom = &room1;
    bool onExit;
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        move = getMove();
        if ( move[0] == '1' ) {player1.move('w');}
        if ( move[1] == '1' ) {player1.move('a');}
        if ( move[2] == '1' ) {player1.move('s');}
        if ( move[3] == '1' ) {player1.move('d');}
        onExit = exit1.hasPlayer(player1.xPos(),player1.yPos());
        if ( onExit == 1 )
            {
            currentRoom = &room2;
            }
        ClearBackground(currentRoom->color);
        player1.draw();
        currentRoom->drawRoom();
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


