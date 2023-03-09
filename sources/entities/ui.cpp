#include "headers/ui.hpp"

void UI::draw() {
	std::sprintf(m_pointsLabelBuffer, "%s:%d", "Points", m_points);
	DrawText((char*)m_pointsLabelBuffer, Settings::screenWidth - 150, Settings::screenHeight / 2 + 10, 20, DARKGRAY);

	std::sprintf(m_levelLabelBuffer, "%s:%d", "Level", m_level);
	DrawText((char*)m_levelLabelBuffer, Settings::screenWidth - 150, Settings::screenHeight / 2 - 10, 20, DARKGRAY);
}

void UI::addPoints() {
	m_points += 100;
}