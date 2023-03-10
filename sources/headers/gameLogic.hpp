#pragma once
#include <vector>
#include "settings.hpp"
#include "car.hpp"
#include "ui.hpp"

class GameLogic {
private:
	bool m_gameStarted = false;
	int m_currentSpeed = 5;
	UI* m_uiElement;
	Car m_playerCar = { 20, Settings::screenHeight - 200 };
	std::vector<Car> m_enemyCars;
	float m_enemyPlayerPostions[2] = { 20, 170 };

public:
	GameLogic(UI* ui);
	Car& getPlayerCar();
	std::vector<Car>& getEnemyCars();
	bool isGameStarted();
	void startGame();
	void generateEnemyCars();
	void clearEnemyCars();
	void drawEnemyCars();
	void moveEnemyCarsDown();
	void setCurrentSpeedLevel(int& level);
	void checkPlayerCarCollisions();
};