#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>

class Object
{
protected: 
	objSize width, height;
	unitPerSecond speed;
	Coord coord;

	//shape
public:
	Object() { width = height = 0; speed = 0; coord = Coord(0, 0); }
	Object(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : width(_w), height(_h), speed(_s), coord(_c) {}
	virtual void Move(Coord);
	virtual void Move(objSize, objSize); //relative objSizes for moves
	friend class Scene;
};

#endif // !_OBJECT_H_

