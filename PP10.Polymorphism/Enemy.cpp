#include "Enemy.h"

void Enemy::update() {
	//GameObject::update();

	//m_y += 1;
	if (g == 0) {
		m_x += 4;
		if (m_x == 500)
		{
			g = 1;
		}
	}
	
	if (g == 1)
	{
		m_x -= 4;
		if (m_x == 0)
		{
			g = 0;
		}
	}

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}