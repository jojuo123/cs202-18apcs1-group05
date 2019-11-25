#include "Player.h"

bool Player::isHit(const Obstacle* &obs) {
	return position.intersects(obs->getPosition());
}