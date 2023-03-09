#pragma once
#include "raylib.h"

class Entity
{
protected:
	Vector2 m_position;

public:
	Entity(int positionX, int positionY);
	virtual void draw() {};
	Vector2 getPosition();
	void setPosition(Vector2 position);
};
