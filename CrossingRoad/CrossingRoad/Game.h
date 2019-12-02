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
	Tile Grass1Tile, Grass2Tile, Grass3Tile, Grass4Tile, RoadTile, FinishTile;
	int rows, columns;
	int currentLevel;
	Player* player;
	vector<deque<Object*> > dqOb;
	//Tile** map;
	vector<vector<Tile> > Map;
	Obstacle* dino, * truck, * tiger, * motor;
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
	//void Init();
	//void Init(string);
	void Init(string chosenPath, int level =1);
	void InitTile();
	void InitMap();
	void AddObject(int _row, ObjectType o);
	void AddTile(int _row, ObjectType o);
	//void InitMap(int, int); 
	void Exit(int option);

	vector<vector<Tile> > GetMap() { return Map; }

	bool isEndGame();
	bool isLevelUp();
	bool isEndGameByCollision();
	int getCurrentLevel() { return currentLevel; };
	~Game()
	{
		//delete map;
		/*for (int i = 0; i < rows; i++)
			delete[] map[i];
		delete[] map;*/
		delete player;
		//delete elements in deque
		for (deque<Object*> &ob : dqOb) {
			while (!ob.empty()) {
				delete ob.front();
				ob.pop_front();
			}
		}
		dqOb.clear();
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
