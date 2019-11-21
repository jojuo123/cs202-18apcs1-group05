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
	Obstacle(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : Object(_w, _h, _s, _c) { }
};

#endif // !_OBJECT_H_

