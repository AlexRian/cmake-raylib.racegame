#include "headers/entity.hpp"

Entity::Entity(int positionX, int positionY) {
	m_position = Vector2{ (float)positionX, (float)positionY };
}

Vector2 Entity::getPosition() {
	return m_position;
}
void Entity::setPosition(Vector2 position) {
	m_position = position;
}