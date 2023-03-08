#include <iostream>
#include <string>
#include "raylib.h"
#include "./headers/gamefield.hpp"
#include "./headers/settings.hpp"
#include "./headers/ui.hpp"
#include "./headers/debug.hpp"
#include "./headers/car.hpp"

int main(void)
{
    Gamefield gamefield;
    UI ui;
    Debug debug { Settings::screenWidth - 150, Settings::screenHeight - 250 };
    Car car{ 20, Settings::screenHeight - 200 };

    InitWindow(Settings::screenWidth, Settings::screenHeight, "Race game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) car.moveRight();
        if (IsKeyDown(KEY_LEFT)) car.moveLeft();

        BeginDrawing();
            ClearBackground(RAYWHITE);

            gamefield.draw();
            ui.draw();
            debug.draw();
            car.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}