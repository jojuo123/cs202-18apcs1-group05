#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include "Object.h"
#include "Predefine.h"
#include "Obstacle.h"
#include "Vehicle.h"
#include "Animal.h"
#include "Dinosaur.h"
#include "Truck.h"
#include "Motorbike.h"
#include "Tiger.h"
#include "Player.h"
#include <vector>
#include "Level.h"
#include <Windows.h>
//#include <SFML/Graphics.hpp>

using namespace std;

//this class is singleton
class Menu
{
private:

public:
	int StartMenu(sf::RenderWindow &window, sf::Font &font);
	int PauseMenu();
};

#endif // !_GAME_H_

