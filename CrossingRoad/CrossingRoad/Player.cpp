#include "Player.h"

bool Player::isHit(const Obstacle* &obs) {
	return position.intersects(obs->getPosition());
}

void Player::playSound()
{
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
}
