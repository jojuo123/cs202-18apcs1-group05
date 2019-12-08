#ifndef _LAMP_H_
#define _LAMP_H_

#include "Predefine.h"
#include "Object.h"

using namespace std;

class Lamp : public Object
{
private:
	int state = 0; //0 = green, 1 = red
	sf::Clock clock;
public:
	Lamp() : Object()
	{
		Object::timer = 0;
	}
	Lamp(unitPerSecond _s, Coord _c, string texturePath, ObjectType _t, sf::Rect<objSize> _pos) : Object(_s, _c, texturePath, "sound/lampSound.wav", _t, _pos)
	{
		Object::timer = _s;
	}
	void ChangeState();
	int GetState() { return state; }
	void Update(int, int, int, int);
};

#endif // !_LAMP_H_

