#include "Obstacle.h"

void Obstacle::UpdatePosition() {
	float t = clock.getElapsedTime().asSeconds();
	float sign = (dir == LEFT ? -1.0 : 1.0);
	int deltaS = round(sign * t * this->speed);
	this->position.left += deltaS;
	clock.restart();
};