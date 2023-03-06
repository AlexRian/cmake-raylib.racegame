#include <iostream>
#include "raylib.h"
#include "./headers/gamefield.h"
#include "./headers/settings.h"
#include "./headers/ui.h"

int main(void)
{
    Gamefield gamefield;
    UI ui;

    InitWindow(Settings::screenWidth, Settings::screenHeight, "Race game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            //Drawing gamefield
            gamefield.draw();
            ui.draw();

            //Drawing player
            DrawRectangle(20, Settings::screenHeight - 200, 150, 200, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}