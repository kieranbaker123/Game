// config.h

#pragma once

namespace config
{
    // layout
    constexpr int wallWidth = 20;
    constexpr int mapHeight = 11;
    constexpr int mapWidth = 11;
    constexpr int screenWidth = 1000;
    constexpr int screenHeight = screenWidth * 3 / 4;
    
    constexpr int FPS = 60;

    constexpr float baseSpeed = screenWidth * 2 * FPS / 60 / 800;
}
