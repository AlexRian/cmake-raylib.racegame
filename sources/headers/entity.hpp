#pragma once

class Entity
{
protected:
	int m_positionX;
	int m_positionY;

public:
	Entity(int positionX, int positionY) {
		m_positionX = positionX;
		m_positionY = positionY;
	}

	virtual void draw() {};
};
