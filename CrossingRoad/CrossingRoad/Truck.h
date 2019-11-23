#ifndef _TRUCK_H_
#define _TRUCK_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Vehicle.h"
#include <string>

class Truck : public Vehicle
{
protected:
	
public:
	Truck() : Vehicle() { }
	Truck(objSize _w, objSize _h, unitPerSecond _s, Coord _c) : Vehicle(_w, _h, _s, _c) { }
	friend class Scene;
};

#endif 
