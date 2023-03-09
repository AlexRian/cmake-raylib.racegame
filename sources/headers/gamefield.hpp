#pragma once
#include "raylib.h"
#include "entity.hpp"

class Gamefield : public Entity {
using Entity::Entity;
public:
	void draw();
};