#ifndef _SCENE_H_
#define _SCENE_H_

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
#include "Game.h"
#include <Windows.h>
#include "Menu.h"

using namespace std;

//this class is singleton
class Scene
{
private:
	Game* g;
	Menu m;
public:
	Scene();
	void Init();
	void Update();
	void Execute();
	void Destroy();
	void Draw();
	void LevelLoader();
	void HandleInput();
	~Scene();
};

#endif // !_GAME_H_

