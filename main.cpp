#include "raylib.h"

int main(void)
{

    const int screenWidth = 1280;
    const int screenHeight = 720;

    SetConfigFlags(FLAG_VSYNC_HINT); // Enable VSYNC
    InitWindow(screenWidth, screenHeight, "Tower Defense");

    SetTargetFPS(60);   
    
    Vector2 squarePosition = { (float)screenWidth / 2 - 25, (float)screenHeight / 2 - 25 };
    const float speed = 5.0f;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_RIGHT)) squarePosition.x += speed;
        if (IsKeyDown(KEY_LEFT)) squarePosition.x -= speed;
        if (IsKeyDown(KEY_UP)) squarePosition.y -= speed;
        if (IsKeyDown(KEY_DOWN)) squarePosition.y += speed;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangleV(squarePosition, (Vector2){ 50.0f, 50.0f }, MAROON);

            DrawFPS(10, 30);

            DrawText("Use arrows to move the cube", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();        
   
    return 0;
}