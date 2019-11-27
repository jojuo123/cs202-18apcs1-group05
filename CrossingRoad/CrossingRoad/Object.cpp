#include "Object.h"

Object::Object(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos):
	coord(_c), speed(_s), type(_t), position(_pos)
{
	using namespace std;
	texture = new sf::Texture;
	if (!texture->loadFromFile(texturePath)) {
		cerr << "Object.cpp deo the load hinh: " << texturePath << endl;
		delete texture;
		texture = nullptr;
	}
	if (!buffer.loadFromFile(soundPath)) {
		cerr << "Object.cpp deo the load am thanh: " << soundPath << endl;
	}
}

void Object::Move(Direction dir, objSize numPixel)
{
	switch (dir) {
	case UP: {
		position.top -= numPixel;
		break;
	}
	case DOWN: {
		position.top += numPixel;
		break;
	}
	case LEFT: {
		position.left -= numPixel;
		break;
	}
	case RIGHT: {
		position.left += numPixel;
		break;
	}
	}
}

void Object::playSound()
{
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
}
