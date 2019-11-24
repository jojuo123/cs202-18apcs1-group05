#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <math.h>
#include "Predefine.h"
#include <algorithm>
#include "Object.h"
#include "Obstacle.h"
#include <string>

class Player : public Object
{
protected:
	std::string name;
	//int state;
	bool isDead;
public:
	Player() : Object() { name = ""; }
	Player(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos) : Object(_s, _c, texturePath, soundPath, _t, _pos) {}
	Player(unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos, std::string _name) : Object(_s, _c, texturePath, soundPath, _t, _pos), name(_name) {}
	bool isHit(const Obstacle* &obs);
	bool inRange();
	friend class Game;
	friend class Scene;
};

#endif // !_OBJECT_H_

