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
#include <SFML/Graphics.hpp>

using namespace std;

//this class is singleton
class Scene
{
private:
	Game* g;
	Menu m;
	sf::RenderWindow window;
	sf::Font menuFont;
	Scene() {
		using namespace sf;
		g = Game::getInstance();
		m = Menu();
		//window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE);
		window.create(VideoMode(800, 600), "Viet cong muon nam");
		menuFont.loadFromFile("verdana.ttf");
	}
	static Scene* sc;

public:
	static Scene* getInstance() {
		if (sc != NULL) return sc;
		sc = new Scene();
		return sc;
	}
	void Init();
	void Update();
	void Execute();
	void Destroy();
	void Draw();
	void LevelLoader();
	void HandleInput();
	~Scene() {
		window.close();
		delete g;
	}
};
//Scene* Scene::sc = nullptr;

#endif // !_GAME_H_

