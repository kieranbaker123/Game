// sprites.cpp

#include"sprites.h"

Sprites sprites;

void LoadSprites()
{
    sprites.arrow = LoadTexture("arrow.png");
}

void UnloadSprites()
{
    UnloadTexture(sprites.arrow);
}
