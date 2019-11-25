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
#include <memory>

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
	//static Game* instance;
	int score;
	int gameState;
	//Game() {}
public:
	Game()
	{
	}
	void StartGame();
	void resetGame();
	void SaveGame(istream);
	void LoadGame(ostream);
	void HandlePlayerInput(int input);
	void Pause(HANDLE);
	void Resume(HANDLE);
	void UpdateObstaclesPosition();
	void Init();
	void InitMap();
	void AddObject(int _row, ObjectType o);
	void AddTile(int _row, ObjectType o);
	void InitMap(int, int); 
	void Exit(int option);
	bool isEndGame();
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
	/*static Game* getInstance() {
		return (instance == nullptr ? instance = new Game() : instance);
	}*/
	void ChangeState(int state);
	friend class Scene;
};
//

#endif // !_GAME_H_
