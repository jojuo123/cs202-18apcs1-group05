#include <iostream>
//#include <SDL.h>
//#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace std;

int main(int argc, char *argv[])
{
	Scene *sc = Scene::getInstance();
	sc->Init();
	sf::sleep(sf::seconds(2.0));
	delete sc;
	return 0;
}