#include "headers/car.hpp"

void Car::draw() {
	DrawRectangle(m_position.x, m_position.y, 50, 50, RED);
	DrawRectangle(m_position.x + m_width - 50, m_position.y, 50, 50, RED);
	DrawRectangle(m_position.x + 50, m_position.y + 50, 50, 50, RED);
	DrawRectangle(m_position.x + 50, m_position.y + 100, 50, 50, RED);
	DrawRectangle(m_position.x, m_position.y + m_height - 50, 50, 50, RED);
	DrawRectangle(m_position.x + m_width - 50, m_position.y + m_height - 50, 50, 50, RED);
}

Rectangle Car::getCollisionArea() {
	Rectangle collisionArea = { m_position.x, m_position.y, 150, 200 };
	return collisionArea;
}

void Car::moveDown() {
	m_position.y += 5;
}
void Car::moveRight() {
	m_position.x = 170;
}
void Car::moveLeft() {
	m_position.x = 20;
}
