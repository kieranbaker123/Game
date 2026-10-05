// main.cpp

#include <string>
#include "raylib.h"
#include "player.h"
#include "config.h"
#include "room.h"
#include <vector>

int main()
{
    std::vector<std::vector<Room>> board;
    Player player1;
    Room room1;
    Room room2;
    Exit exit2;
    Exit exit1;
    exit1.initExit(450, 0, 60, 20, 2, 480, 70);
    room1.addExit(exit1);
    exit2.initExit(450, 580, 60, 20, 1, 480, 530);
    room2.addExit(exit2);
    room1.setID(1);
    room2.setID(2);
    room1.color = WHITE;
    room2.color = GRAY;
    player1.setx(50);
    player1.sety(50);
    constexpr char windowName[] = "Game";
    InitWindow(config::screenWidth, config::screenHeight, windowName );
    SetTargetFPS(60);
    Room* currentRoom = &room1;
    bool onExit;
    std::vector<Room> rooms {room1, room2};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        player1.playerUpdate(player1.getMove());
        onExit = (currentRoom->getExits())[0].hasPlayer(player1.xPos(),player1.yPos());
        if ( onExit == 1 )
            {
            currentRoom = &rooms[(currentRoom->getExits())[0].getDestination() - 1];
            player1.setx((currentRoom->getExits())[0].getaX());
            player1.sety((currentRoom->getExits())[0].getaY());
            }
        ClearBackground(currentRoom->color);
        player1.draw();
        currentRoom->drawRoom();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

