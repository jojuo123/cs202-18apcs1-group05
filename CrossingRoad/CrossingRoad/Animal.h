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
	
public:
	Animal() : Obstacle() { }
	Animal(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos) : Obstacle(_s, _c, texturePath, soundPath, _t, _pos) {}
	//virtual void PlaySound();
	friend class Scene;
};

#endif 


