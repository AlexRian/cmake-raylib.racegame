#include <iostream>
#include "raylib.h"

int main(void)
{
    const int screenWidth = 100;
    const int screenHeight = 100;

    InitWindow(screenWidth, screenHeight, "Race game");

    SetTargetFPS(1);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}