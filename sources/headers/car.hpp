#pragma once
#include "raylib.h"
#include "entity.hpp"

class Car: public Entity
{
using Entity::Entity;

private:
	int m_width = 150;
	int m_height = 200;

public:
	void draw() {
		DrawRectangle(m_position.x, m_position.y, 50, 50, RED);
		DrawRectangle(m_position.x + m_width - 50, m_position.y, 50, 50, RED);
		DrawRectangle(m_position.x + 50, m_position.y + 50, 50, 50, RED);
		DrawRectangle(m_position.x + 50, m_position.y + 100, 50, 50, RED);
		DrawRectangle(m_position.x, m_position.y + m_height - 50, 50, 50, RED);
		DrawRectangle(m_position.x + m_width - 50, m_position.y + m_height - 50, 50, 50, RED);
	}

	Rectangle getCollisionArea() {
		Rectangle collisionArea = { m_position.x, m_position.y, 150, 200 };
		return collisionArea;
	}

	void moveDown() {
		m_position.y += 5;
	}

	void moveRight() {
		m_position.x = 170;
	}

	void moveLeft() {
		m_position.x = 20;
	}
};
