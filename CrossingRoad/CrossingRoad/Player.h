#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Obstacle.h"
#include <string>

class Player : public Object
{
protected:
	std::string name;
	//int score;
public:
	Player() : Object() { name = ""; }
	Player(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : Object(_w, _h, _s, _c) { name = ""; }
	Player(objSize _w, objSize _h, unitPerSecond _s, Coord _c, string _name) : Object(_w, _h, _s, _c), name(_name) {}
	bool isHit(Obstacle *o);
};

#endif // !_OBJECT_H_

