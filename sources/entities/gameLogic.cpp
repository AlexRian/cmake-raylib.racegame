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
void GameLogic::generateEnemyCars() {
	m_enemyCars = {
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -200},
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -700},
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -1200},
		Car {(int)m_enemyPlayerPostions[rand() % (1 - 0 + 1) + 0], -1500},
	};
};
void GameLogic::drawEnemyCars() {
	for (auto& enemyCar : m_enemyCars) {
		enemyCar.draw();
	}
};
std::vector<Car>& GameLogic::getEnemyCars() {
	return m_enemyCars;
};
void GameLogic::moveEnemyCarsDown() {
	for (auto& enemyCar : m_enemyCars) {
		enemyCar.moveDown();
		if (enemyCar.getPosition().y > 900) {
			m_enemyCars.erase(m_enemyCars.begin());
			if (m_enemyCars.size() == 0) {
				generateEnemyCars();
			}
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