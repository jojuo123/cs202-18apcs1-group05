#ifndef _TIGER_H_
#define _TIGER_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Animal.h"
#include <string>

class Tiger : public Animal
{
protected:

public:
	Tiger() : Animal() { }
	Tiger(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos) : Animal(_s, _c, texturePath, soundPath, _t, _pos) {}
	//void PlaySound();
	friend class Scene;
};

#endif 

