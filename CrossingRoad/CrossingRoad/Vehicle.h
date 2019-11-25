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
	Vehicle(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos) : Obstacle(_s, _c, texturePath, soundPath, _t, _pos) {}
	friend class Scene;
};

#endif 


