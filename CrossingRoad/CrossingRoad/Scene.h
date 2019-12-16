#ifndef _SCENE_H_
#define _SCENE_H_

#include <iostream>
#include <fstream>
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
#include "Tile.h"
#include "Menu.h"
//#include <SFML/Graphics.hpp>

using namespace std;

//this class is singleton
class Scene
{
private:
	Game* g;
	Menu m;
	sf::RenderWindow window;
	sf::Font menuFont;
	sf::SoundBuffer gameOverSoundBuffer;
	sf::Sound gameOverSound;
	Scene();
	
	static Scene* sc;
private:
	void Draw(const Object *obj);
	void Draw(const Tile *tile);
	void Draw(const Tile&tile);
	void UpdateCamera();

public:
	static Scene* getInstance() {
		if (sc != NULL) return sc;
		sc = new Scene();
		return sc;
	}
	void Init();
	void Update();
	Object* checkCollision();
	void Execute();
	void Draw(vector<vector<Tile> > &Map);
	void DrawMap(vector<vector<Tile> > &Map);
	void DrawObject(deque<Object*> dqOb);
	void DrawLamp(vector<Lamp> &);
	
	void HandleInput();
	void EndOfGame();
	~Scene();
};

#endif // !_GAME_H_

