#ifndef _GAME_H_
#define _GAME_H_

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

using namespace std;

//this class is singleton
class Game
{
private:
	int currentLevel;
	Player* player;
	Level l;
	int currentRoad;
	static Game* instance;
	Game();
public:
	void StartGame();
	void resetGame();
	void SaveGame(istream);
	void LoadGame(ostream);
	void HandlePlayerInput(int);
	void Pause(HANDLE);
	void Resume(HANDLE);
	void UpdateObstaclesPosition();
	void Exit(int option);
	~Game();
	static Game* getInstance();
	friend class Scene;
};

#endif // !_GAME_H_
