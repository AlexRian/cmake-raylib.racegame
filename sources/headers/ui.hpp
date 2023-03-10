#pragma once
#include <iostream>
#include "raylib.h"
#include "headers/settings.hpp"
#include "headers/entity.hpp"

class UI: public Entity {
using Entity::Entity;
private:
	int m_points = 0;
	int m_level = 1;
	char m_pointsLabelBuffer[20];
	char m_levelLabelBuffer[20];

public:
	void draw();
	void addPoints();
	void drawHelpMessage();
	void increaseLevel();
	void decreaseLevel();
	void clearPoints();
	int& getSelectedLevel();
};