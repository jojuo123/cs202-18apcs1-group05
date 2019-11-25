#include <iostream>
//#include <SDL.h>
//#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace std;

int main(int argc, char *argv[])
{
	Scene *sc = Scene::getInstance();
	sc->Init();
	sc->Execute();

	delete sc;
	return 0;
}