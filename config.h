// config.h

#pragma once

namespace config
{
    // layout
    constexpr float scalingFactor = 1.25;

    constexpr int wallWidth = 20;
    constexpr int mapHeight = 11;
    constexpr int mapWidth = 11;
    constexpr int screenWidth = 800.0 * scalingFactor;
    constexpr int screenHeight = screenWidth * 3 / 4;
    
    constexpr int FPS = 60;

    constexpr float baseSpeed = screenWidth * 2 * FPS / 60 / 800;
    constexpr int playerSize = 10 * scalingFactor;

    constexpr int arrowLen = 44 * scalingFactor;
    constexpr int arrowWid = 8 * scalingFactor;


}
