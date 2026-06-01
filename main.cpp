#pragma once
#include "raylib.h"

int main(void)
{

    const int screenWidth = 1280;
    const int screenHeight = 720;

    SetConfigFlags(FLAG_VSYNC_HINT); // Enable VSYNC
    InitWindow(screenWidth, screenHeight, "Tower Defense");

    SetTargetFPS(60); 



    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
    }

    CloseWindow();        
   
    return 0;
}