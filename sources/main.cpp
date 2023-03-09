#include <iostream>
#include <string>
#include "raylib.h"
#include "./headers/gamefield.hpp"
#include "./headers/settings.hpp"
#include "./headers/ui.hpp"
#include "./headers/debug.hpp"
#include "./headers/car.hpp"
#include "./headers/gameLogic.hpp"

int main(void)
{
    Gamefield gamefield{0,0};
    UI ui{0,0};
    Debug debug{ Settings::screenWidth - 150, Settings::screenHeight - 250, false };

    GameLogic gameLogic{&ui};

    InitWindow(Settings::screenWidth, Settings::screenHeight, "Race game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) gameLogic.getPlayerCar().moveRight();
        if (IsKeyDown(KEY_LEFT)) gameLogic.getPlayerCar().moveLeft();

        BeginDrawing();
            ClearBackground(RAYWHITE);

            gamefield.draw();
            ui.draw();
            debug.draw();
            
            gameLogic.getPlayerCar().draw();
            if (gameLogic.isGameStarted()) {
                gameLogic.moveEnemyCarsDown();
                gameLogic.checkPlayerCarCollisions();
            }
            gameLogic.drawEnemyCars();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}