#pragma once
#include "raylib.h"

class Entity
{
protected:
	Vector2 m_position;

public:
	Entity(int positionX, int positionY) {
		m_position = Vector2{ (float)positionX, (float)positionY };
	}

	virtual void draw() {};

	Vector2 getPosition() {
		return m_position;
	}

	void setPosition(Vector2 position) {
		m_position = position;
	}
};
