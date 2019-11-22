#ifndef _DINOSAUR_H_
#define _DINOSAUR_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Animal.h"
#include <string>

class Dinosaur : public Animal
{
protected:

public:
	Dinosaur() : Animal() { }
	Dinosaur(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : Animal(_w, _h, _s, _c) { }
	Dinosaur(objSize _w, objSize _h, unitPerSecond _s, Coord _c, int _a) : Animal(_w, _h, _s, _c, _a) { }
	void PlaySound();
	friend class Scene;
};

#endif 