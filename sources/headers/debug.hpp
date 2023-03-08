#pragma once
#include <vector>
#include "raylib.h"

class Debug
{
private:
	int m_positionX;
	int m_positionY;
	std::vector<std::string> m_messages {};

public:
	Debug(int positionX, int positionY) {
		m_positionX = positionX;
		m_positionY = positionY;
	}

	void draw() {
		DrawRectangle(m_positionX, m_positionY, 150, 250, BLACK);
		if (!m_messages.empty()) {
			for (int i = m_messages.size() - 1; i >= 0; --i) {
				DrawText(m_messages[i].c_str(), m_positionX + 10, m_positionY + i * 20, 20, WHITE);
			}
		}
	}

	void log(std::string message) {
		if (m_messages.size() == 12) {
			m_messages.erase(m_messages.begin());
		}
		m_messages.push_back(message);
	}
};