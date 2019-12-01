#include "Player.h"

bool Player::isHit(Object *&obj) {
	return position.intersects(obj->getPosition());
}

void Player::Move(Direction dir, objSize numPixel)
{
	switch (dir) {
	case UP: {
		//if (coord.y > 0) {
		//	//if (?)
		//	int numRowOnScr = SCREEN_HEIGHT / PIXEL_SIZE;
		//	if (coord.y < numRowOnScr) { //0..numRowOnScr-1
		//		Object::Move(dir, numPixel);
		//	}
		//	coord.y--;
		//}
		coord.y--;
		Object::Move(dir, numPixel);
		break;
	}
	case DOWN: {
		//int numRowOnScr = SCREEN_HEIGHT / PIXEL_SIZE;
		//if (coord.y < numRowOnScr-1) { //0..numRowOnScr-2
		//	Object::Move(dir, numPixel);
		//}
		//coord.y++;
		coord.y++;
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
