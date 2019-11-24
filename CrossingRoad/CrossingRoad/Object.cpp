#include "Object.h"

Object::Object(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos):
	coord(_c), speed(_s), type(_t), position(_pos)
{
	using namespace std;
	texture = new sf::Texture;
	if (!texture->loadFromFile(texturePath)) {
		cerr << "Deo the load hinh: " << texturePath << endl;
		delete texture;
		texture = nullptr;
	}
	if (!buffer.loadFromFile(soundPath)) {
		cerr << "Deo the load am thanh: " << soundPath << endl;
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
