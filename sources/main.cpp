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
    Car enemyCar{ 170, Settings::screenHeight - 800 };

    bool gameStarted = true;
    float enemyPlayerPostions[2] = { 20, 170 };

    InitWindow(Settings::screenWidth, Settings::screenHeight, "Race game");

    SetTargetFPS(120);

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
            enemyCar.draw();

            if (gameStarted) {
                enemyCar.moveDown();
                if (enemyCar.getPosition().y > 900) {
                    enemyCar.setPosition(Vector2{ enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -200 });
                    ui.addPoints();
                }
            }

            if (CheckCollisionRecs(car.getCollisionArea(), enemyCar.getCollisionArea())) {
                gameStarted = false;
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}