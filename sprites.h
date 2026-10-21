// sprites.h

#pragma once

#include"raylib.h"

#define arrowTypes 3

struct Sprites
{
    Texture2D arrow[arrowTypes];
};

extern Sprites sprites;

void LoadSprites();
void UnloadSprites();
