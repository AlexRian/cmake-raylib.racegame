#include <iostream>
#include <string>
#include "raylib.h"
#include "./headers/gamefield.h"
#include "./headers/settings.h"
#include "./headers/ui.h"
#include "./headers/debug.hpp"

int main(void)
{
    Gamefield gamefield;
    UI ui;
    Debug debug{ Settings::screenWidth - 150, Settings::screenHeight - 250 };

    InitWindow(Settings::screenWidth, Settings::screenHeight, "Race game");

    SetTargetFPS(60);

    int count = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            //Drawing gamefield
            gamefield.draw();
            ui.draw();
            debug.draw();
            count++;
            debug.log("test" + std::to_string(count));

            //Drawing player
            DrawRectangle(20, Settings::screenHeight - 200, 150, 200, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}