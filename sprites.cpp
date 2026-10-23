// sprites.cpp

#include"sprites.h"

Sprites sprites;

void LoadSprites()
{
    // player arrows
    sprites.arrow[0] = LoadTexture("sprites/arrow0.png");
    sprites.arrow[1] = LoadTexture("sprites/arrow1.png");
    sprites.arrow[2] = LoadTexture("sprites/arrow2.png");

    sprites.clubTroll = LoadTexture("sprites/Enemies/clubTroll.png");
    sprites.clubTrollAttack[0] = LoadTexture("sprites/Enemies/clubTrollAttack0.png");
    sprites.clubTrollAttack[1] = LoadTexture("sprites/Enemies/clubTrollAttack1.png");
    sprites.clubTrollAttack[2] = LoadTexture("sprites/Enemies/clubTrollAttack2.png");
    sprites.clubTrollAttack[3] = LoadTexture("sprites/Enemies/clubTrollAttack3.png");
}

void UnloadSprites()
{
    int i;
    for ( i = 0; i < arrowTypes; i++ )
    {
        UnloadTexture(sprites.arrow[i]);
    }

    UnloadTexture(sprites.clubTroll);

    for ( i = 0; i < 4; i++ )
    {
        UnloadTexture(sprites.clubTrollAttack[i]);
    }    
}
