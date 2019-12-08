#include "Lamp.h"

void Lamp::ChangeState()
{
	state = !state;
	Object::texture->loadFromFile("image/light" + std::to_string(state) + ".png");
}

void Lamp::Update(int minR, int maxR, int minG, int maxG)
{
	float t = clock.getElapsedTime().asSeconds();
	if (t >= Object::timer)
	{
		ChangeState();
		Object::timer = (state)?rand() % (maxG - minG) + minG : rand() % (maxR - minR) + minR;
		clock.restart();
	}
	//clock.restart();
}


