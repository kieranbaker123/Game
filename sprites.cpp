// sprites.cpp

#include"sprites.h"

Sprites sprites;

void LoadSprites()
{
    // player arrows
    sprites.arrow[0] = LoadTexture("sprites/arrow1.png");
    sprites.arrow[1] = LoadTexture("sprites/arrow2.png");
    sprites.arrow[2] = LoadTexture("sprites/arrow3.png");
}

void UnloadSprites()
{
    int i;
    for ( i = 0; i < arrowTypes; i++ )
    {
        UnloadTexture(sprites.arrow[i]);
    }
}
