#include "Lamp.h"

void Lamp::ChangeState()
{
	state = !state;
	Object::texture->loadFromFile("image/light" + std::to_string(state) + ".png");
}

void Lamp::Update()
{
	float t = clock.getElapsedTime().asSeconds();
	if (t >= Object::timer)
	{
		ChangeState();
		Object::timer = rand() % 5 + 2;
		clock.restart();
	}
	//clock.restart();
}


