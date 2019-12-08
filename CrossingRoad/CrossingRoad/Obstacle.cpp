#include "Obstacle.h"

void Obstacle::UpdatePosition(bool isRunning) {
	if (isRunning)
	{
		float t = clock.getElapsedTime().asSeconds();
		float sign = (dir == LEFT ? -1.0 : 1.0);
		int deltaS = round(sign * t * this->speed);
		this->position.left += deltaS;
	}
	clock.restart();
}

Obstacle & Obstacle::operator=(const Obstacle & obs)
{
	if (this == &obs) return *this;
	Object::operator=(obs);
	clock.restart();
	return *this;
}