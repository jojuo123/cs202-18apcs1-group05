#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include <string>

class Obstacle : public Object
{
protected:
	
public:
	Obstacle() : Object() {  }
	Obstacle(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos) : Object(_s, _c, texturePath, soundPath, _t, _pos) {}
	static Obstacle* Create(ObjectType type, unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos);
};

#endif // !_OBJECT_H_

