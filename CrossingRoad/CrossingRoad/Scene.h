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
	//Tile** map = nullptr;
	Game* g;
	Menu m;
	sf::RenderWindow window;
	sf::Font menuFont;
	sf::SoundBuffer gameOverSoundBuffer;
	sf::Sound gameOverSound;
	Scene() {
		using namespace sf;
		//g = Game::getInstance();
		m = Menu();
		//window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE);
		window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Viet cong muon nam");
		menuFont.loadFromFile("verdana.ttf");
		gameOverSoundBuffer.loadFromFile("sound/vvh.wav");
		gameOverSound.setBuffer(gameOverSoundBuffer);
	}
	
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
	void checkCollision();
	void Execute();
	void Destroy();
	void Draw(vector<vector<Tile> > &Map);
	void DrawMap(vector<vector<Tile> > &Map);
	void DrawObject(deque<Object*> dqOb);
	void DrawLamp(vector<Lamp> &);
	void Pause();
	
	void HandleInput();
	void Start()
	{
		//g = Game::getInstance();
		
	}
	void EndOfGame()
	{
		delete g;
		g = NULL;
	}

	//void InitMap();
	void LevelLoader();
	~Scene() {
		window.close();
		delete g;
	}
};
//Scene* Scene::sc = nullptr;

#endif // !_GAME_H_

