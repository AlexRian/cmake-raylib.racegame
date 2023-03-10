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

void UI::drawHelpMessage() {
	DrawText("Choose level via \n UP/down arrow keys", Settings::screenWidth - 160, Settings::screenHeight / 2 - 70, 15, DARKGRAY);
}

void UI::increaseLevel()
{
	if ((m_level + 1) > 10) return;
	m_level++;
}

void UI::decreaseLevel()
{
	if ((m_level - 1) < 1) return;
	m_level--;
}

void UI::clearPoints()
{
	m_points = 0;
}

int& UI::getSelectedLevel()
{
	return m_level;
}
