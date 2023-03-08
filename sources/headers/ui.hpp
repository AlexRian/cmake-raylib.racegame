#pragma once
#include "raylib.h"

class UI {
private:
	int m_points = 0;
	int m_level = 0;
	char m_pointsLabelBuffer[20];
	char m_levelLabelBuffer[20];
public:
	void draw() {
		sprintf(m_pointsLabelBuffer, "%s:%d", "Points", m_points);
		DrawText((char*)m_pointsLabelBuffer, Settings::screenWidth - 150, Settings::screenHeight / 2 + 10, 20, DARKGRAY);
		
		sprintf(m_levelLabelBuffer, "%s:%d", "Level", m_level);
		DrawText((char*)m_levelLabelBuffer, Settings::screenWidth - 150, Settings::screenHeight / 2 - 10, 20, DARKGRAY);
	};
	void addPoints() {
		m_points += 100;
	}
};