#include "Object.h"

Object::Object(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos):
	speed(_s), coord(_c), type(_t), position(_pos)
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

void Object::setDirection(Direction _dir)
{
	this->dir = _dir;
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

void Object::playSound(bool on)
{
	if (on) {
		sound.setBuffer(buffer);
		sound.play();
		//while (sound.getStatus() == sf::Sound::Playing) //Wait for playing done.
		//{
		//	sf::sleep(sf::milliseconds(10));
		//}
	}
}

bool Object::isOutOfScreen()
{
	sf::IntRect screenRect(-3 * PIXEL_SIZE, -3 * PIXEL_SIZE, SCREEN_WIDTH * 2, 0x3c3c3c3c);
	return !(this->position.intersects(screenRect));
}

Object & Object::operator=(const Object & obj)
{
	if (this == &obj) return *this;
	this->speed = obj.speed;
	this->position = obj.position;
	delete this->texture;
	this->texture = (obj.texture != NULL) ? new sf::Texture(*obj.texture) : NULL;
	this->isMoving = obj.isMoving;
	this->type = obj.type;
	this->coord = obj.coord;
	this->buffer = obj.buffer;
	this->dir = obj.dir;
	return *this;
}

void Object::UpdatePosition(bool isRunning)
{

}
