// sprites.h

#pragma once

#include"raylib.h"

#define arrowTypes 3

struct Sprites
{
    Texture2D arrow[arrowTypes];
    Texture2D clubTroll;
    Texture2D clubTrollAttack[4];
};

extern Sprites sprites;

void LoadSprites();
void UnloadSprites();
