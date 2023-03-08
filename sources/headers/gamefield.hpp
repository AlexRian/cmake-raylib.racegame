#pragma once
#include "raylib.h"

class Gamefield {
public:
	void draw() {
		DrawRectangle(10, 0, 10, 800, BLACK);
		DrawRectangle(320, 0, 10, 800, BLACK);
	};
};