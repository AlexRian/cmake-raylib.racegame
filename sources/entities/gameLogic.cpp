#include "headers/gameLogic.hpp"

GameLogic::GameLogic(UI* ui) {
	m_uiElement = ui;
	generateEnemyCars();
}
Car& GameLogic::getPlayerCar() {
	return m_playerCar;
}
bool GameLogic::isGameStarted() {
	return m_gameStarted;
}
void GameLogic::startGame()
{
	m_gameStarted = true;
}
void GameLogic::generateEnemyCars() {
	m_enemyCars = {
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -200},
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -800},
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -1300},
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -1800},
	};
}
void GameLogic::clearEnemyCars()
{
	m_enemyCars.clear();
	generateEnemyCars();
}
;
void GameLogic::drawEnemyCars() {
	for (auto& enemyCar : m_enemyCars) {
		enemyCar.draw();
	}
};
std::vector<Car>& GameLogic::getEnemyCars() {
	return m_enemyCars;
};
void GameLogic::setCurrentSpeedLevel(int& level) {
	m_currentSpeed = level;
};
void GameLogic::moveEnemyCarsDown() {
	for (auto& enemyCar : m_enemyCars) {
		enemyCar.moveDown(m_currentSpeed);
		if (enemyCar.getPosition().y > 900) {
			m_enemyCars.erase(m_enemyCars.begin());
			m_enemyCars.push_back(Car{ (int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -1300});

			m_uiElement -> addPoints();
		}
	}
}
void GameLogic::checkPlayerCarCollisions() {
	for (auto& enemyCar : m_enemyCars) {
		if (CheckCollisionRecs(m_playerCar.getCollisionArea(), enemyCar.getCollisionArea())) {
			m_gameStarted = false;
		}
	}
}