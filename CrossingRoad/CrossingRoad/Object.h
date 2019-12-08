#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>

class Object
{
protected: 
	//objSize width, height;
	union
	{
		unitPerSecond speed;
		unitPerSecond timer;
	};
	sf::Rect<objSize> position;
	sf::Texture* texture;
	bool isMoving = false;
	ObjectType type;
	Coord coord; //LET IT MOVE TO PLAYER.h. In any case, rebuild it here :<
	sf::SoundBuffer buffer;
	Direction dir; //<- What is this?
	//bool isDead = false;
	//shape
public:
	Object() { position = { 0, 0, 0, 0 }; speed = 0; texture = nullptr; }
	Object(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos);
	void setDirection(Direction _dir);
	//virtual void Move(Coord);
	//virtual void Move(objSize, objSize); //relative objSizes for moves
	virtual void Move(Direction dir, objSize numPixel);
	sf::Rect<objSize> getPosition() const { return position; }
	void playSound();
	//virtual void UpdatePosition();
	//bool isOutOfScreen();
	Direction getDirection() { return dir; }
	friend class Scene;
	virtual ~Object()
	{
		delete texture;
	}
	virtual void UpdatePosition(bool isRunning = true);
	bool isOutOfScreen();
	Object& operator= (const Object& obj);
	void setPosition(sf::IntRect pos) { this->position = pos; }
};

#endif // !_OBJECT_H_

