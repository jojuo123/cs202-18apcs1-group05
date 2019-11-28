#include "Player.h"

bool Player::isHit(const Obstacle* &obs) {
	return position.intersects(obs->getPosition());
}

void Player::Move(Direction dir, objSize numPixel)
{
	switch (dir) {
	case UP: {
		coord.y++;
		Object::Move(dir, numPixel);
		break;
	}
	case DOWN: {
		coord.y--;
		Object::Move(dir, numPixel);
		break;
	}
	case LEFT: {
		coord.x--;
		Object::Move(dir, numPixel);
		break;
	}
	case RIGHT: {
		coord.x++;
		Object::Move(dir, numPixel);
		break;
	}
	}
}

void Player::playSound()
{
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
}
