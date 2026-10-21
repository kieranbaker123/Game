// sprites.h

#pragma once

#include"raylib.h"

struct Sprites
{
    Texture2D arrow;

};

extern Sprites sprites;

void LoadSprites();
void UnloadSprites();
