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
#include "Tile.h"
#include <Windows.h>
#include <queue>

using namespace std;

//this class is singleton
class Game
{
private:
	int rows, columns;
	int currentLevel;
	Player* player;
	deque<Object*> dqOb;
	Tile** map;
	Obstacle* dino, * truct, * tiger, * motor;
	Level l;
	int FPS;
	int currentRoad;
	static Game* instance;
	Game() {}
public:
	void StartGame();
	void resetGame();
	void SaveGame(istream);
	void LoadGame(ostream);
	void HandlePlayerInput(int);
	void Pause(HANDLE);
	void Resume(HANDLE);
	void UpdateObstaclesPosition();
	void Init();
	void AddObject(int _row);
	void InitMap(int, int); 
	void Exit(int option);
	~Game()
	{
		//delete map;
		for (int i = 0; i < rows; i++)
			delete[] map[i];
		delete[] map;
		delete player;
		//delete elements in deque
		//delete object
	}
	static Game* getInstance() {
		return (instance == nullptr ? instance = new Game() : instance);
	}
	friend class Scene;
};
//

#endif // !_GAME_H_
