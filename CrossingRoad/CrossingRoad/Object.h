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
	Coord coord;
	sf::SoundBuffer buffer;
	Direction dir; //<- What is this?
	//bool isDead = false;
	//shape
public:
	Object() { position = { 0, 0, 0, 0 }; speed = 0; coord = Coord(0, 0); texture = nullptr; }
	Object(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos);
	//virtual void Move(Coord);
	//virtual void Move(objSize, objSize); //relative objSizes for moves
	virtual void Move(Direction dir, objSize numPixel);
	sf::Rect<objSize> getPosition() const { return position; }
	friend class Scene;
	virtual ~Object()
	{
		delete texture;
	}
};

#endif // !_OBJECT_H_

