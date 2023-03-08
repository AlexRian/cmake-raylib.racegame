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
		DrawRectangle(m_positionX, m_positionY, 50, 50, RED);
		DrawRectangle(m_positionX + m_width - 50, m_positionY, 50, 50, RED);
		DrawRectangle(m_positionX + 50, m_positionY + 50, 50, 50, RED);
		DrawRectangle(m_positionX + 50, m_positionY + 100, 50, 50, RED);
		DrawRectangle(m_positionX, m_positionY + m_height - 50, 50, 50, RED);
		DrawRectangle(m_positionX + m_width - 50, m_positionY + m_height - 50, 50, 50, RED);
	}

	void moveRight() {
		m_positionX = 170;
	}

	void moveLeft() {
		m_positionX = 20;
	}
};
