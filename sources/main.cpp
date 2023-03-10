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

    GameStages curentStage = GameStages::settings;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            gamefield.draw();
            ui.draw();
            debug.draw();
            gameLogic.getPlayerCar().draw();
            
            if (curentStage == GameStages::settings) {
                if (IsKeyPressed(KEY_UP)) ui.increaseLevel();
                if (IsKeyPressed(KEY_DOWN)) ui.decreaseLevel();
                if (IsKeyPressed(KEY_ENTER)) {
                    gameLogic.setCurrentSpeedLevel(ui.getSelectedLevel());
                    curentStage = GameStages::arena;
                    gameLogic.startGame();
                }

                ui.drawHelpMessage();
            }
            else 
            {
                if (IsKeyPressed(KEY_R)) {
                    gameLogic.clearEnemyCars();
                    ui.clearPoints();
                    curentStage = GameStages::settings;
                }

                if (gameLogic.isGameStarted()) {
                    if (IsKeyDown(KEY_RIGHT)) gameLogic.getPlayerCar().moveRight();
                    if (IsKeyDown(KEY_LEFT)) gameLogic.getPlayerCar().moveLeft();

                    gameLogic.moveEnemyCarsDown();
                    gameLogic.checkPlayerCarCollisions();
                }
                gameLogic.drawEnemyCars();
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}