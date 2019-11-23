#ifndef _MOTORBIKE_H_
#define _MOTORBIKE_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Vehicle.h"
#include <string>

class Motorbike : public Vehicle
{
protected:

public:
	Motorbike() : Vehicle() { }
	Motorbike(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : Vehicle(_w, _h, _s, _c) { }
	friend class Scene;
};

#endif 
