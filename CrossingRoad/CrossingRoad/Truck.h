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
	Truck(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos) : Vehicle(_s, _c, texturePath, soundPath, _t, _pos) {}
	friend class Scene;
};

#endif 
