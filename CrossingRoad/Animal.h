#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Obstacle.h"
#include <string>

class Animal  : public Obstacle
{
protected:
	int audioId;
public:
	Animal() : Obstacle() { }
	Animal(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : Obstacle(_w, _h, _s, _c) { }
	Animal(objSize _w, objSize _h, unitPerSecond _s, Coord _c, int _a) : Obstacle(_w, _h, _s, _c), audioId(_a) { }
	virtual void PlaySound();
	friend class Scene;
};

#endif 


