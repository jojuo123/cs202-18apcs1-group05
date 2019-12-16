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
#include "Lamp.h"
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
	vector<Lamp> lampList;
	vector<int>  spaceObs;
	vector<vector<Tile> > Map;
	//Obstacle* dino, * truck, * tiger, * motor;
	Level l;
	//int currentRoad;
	int score;
	int gameState;
public:
	Game() = default;
	void StartGame();
	void HandlePlayerInput(int input, bool soundOn=true);
	void UpdateObstaclesPosition();
	void generateObject();
	void Init(string chosenPath, int level =1);
	void InitTile();
	void InitMap();
	void AddLamp(int _row, ObjectType o);
	void AddObject(int _row, ObjectType o);
	void AddTile(int _row, ObjectType o);
	vector<vector<Tile> > GetMap() { return Map; }
	bool isEndGame();
	bool isLevelUp();
	bool isEndGameByCollision();
	int getCurrentLevel() { return currentLevel; };
	~Game();
	void ChangeState(int state);
	friend class Scene;
};

#endif // !_GAME_H_
