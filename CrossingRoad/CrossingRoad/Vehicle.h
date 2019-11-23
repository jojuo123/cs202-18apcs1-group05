#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Obstacle.h"
#include <string>

class Vehicle : public Obstacle
{
protected:
	
public:
	Vehicle() : Obstacle() { }
	Vehicle(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : Obstacle(_w, _h, _s, _c) { }
	friend class Scene;
};

#endif 


