#pragma once
#include "raylib.h"
#include "entity.hpp"

class Car : public Entity
{
	using Entity::Entity;

private:
	int m_width = 150;
	int m_height = 200;

public:
	void draw();
	Rectangle getCollisionArea();
	void moveDown(int& level);
	void moveRight();
	void moveLeft();
};
