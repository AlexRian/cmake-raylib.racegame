#pragma once
#include "raylib.h"

class UI {
public:
	void draw() {
		DrawText("Score: 1400", Settings::screenWidth - 150, Settings::screenHeight / 2 + 10, 20, DARKGRAY);
		DrawText("Level: 10", Settings::screenWidth - 150, Settings::screenHeight / 2 - 10, 20, DARKGRAY);
	};
};