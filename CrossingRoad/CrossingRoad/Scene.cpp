#include "Scene.h"

using namespace std;
Scene* Scene::sc = nullptr;
void Scene::Draw(const Object * obj)
{
	if (obj->texture == nullptr) return;
	sf::Sprite sprite(*(obj->texture));
	sf::Vector2u v = obj->texture->getSize();
	float scaleX = obj->position.width / (float)v.x;
	float scaleY = obj->position.height / (float)v.y;
	sprite.setScale(scaleX, scaleY);
	sprite.setPosition(obj->position.left, obj->position.top);
	window.draw(sprite);
}
void Scene::Draw(const Tile * tile)
{
	if (tile->texture == nullptr) return;
	sf::Sprite sprite(*(tile->texture));
	sprite.setPosition(tile->position.left, tile->position.top);
	window.draw(sprite);
}
void Scene::Init() {
	int sel = m.StartMenu(window, menuFont);
	switch (sel)
	{
	case (MENU_STARTGAME): {
		window.setFramerateLimit(60);
		g = new Game();
		//g->Init();
		g->Init(m.chosenPathValue());
		break;
	}
	case (MENU_LOADGAME): {
		int savedLevel=-1;
		ifstream fin("SavedLevel.txt", ifstream::in);
		if (fin.is_open())
		{
			fin >> savedLevel;
			fin.close();
			if (savedLevel != -1)
			{
				g = new Game();
				g->Init(m.chosenPathValue(), savedLevel);
			}
			else
			{
				cerr << "No saved game exist";
				fin.close();
				this->Init();
			}
		}
		break;
	}
	case (MENU_SETTING):
	{
		m.SettingMenu(window,menuFont);
		this->Init();
		break;
	}
	case (MENU_EXIT): {
		cerr << "EXIT" << endl;
		break;
	}
	}
}

void Scene::Execute()
{
	while (g != nullptr) {
		HandleInput();
		if (g->isEndGame())
		{
			EndOfGame();
			break;
		}
		Draw();
	}
}

void Scene::Draw()
{
	window.clear();
	//Draw all of g (Tiles, obstacles beforehand)
	Draw(g->player);
	window.display();
}

void Scene::HandleInput()
{
	using namespace sf;
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up) {
				g->HandlePlayerInput(PLAYERINPUT_MOVEUP);
			}
			if (event.key.code == Keyboard::Down) {
				g->HandlePlayerInput(PLAYERINPUT_MOVEDOWN);
			}
			if (event.key.code == Keyboard::Left) {
				g->HandlePlayerInput(PLAYERINPUT_MOVELEFT);

			}
			if (event.key.code == Keyboard::Right) {
				g->HandlePlayerInput(PLAYERINPUT_MOVERIGHT);
			}
			if (event.key.code == Keyboard::Escape) {
				int sel = m.PauseMenu(window, menuFont);
				if (sel == 0) //continue
				{
					window.clear();
					continue;
				}
				else if (sel == 1) // reset 
				{
					window.clear();
					window.setFramerateLimit(60);
					EndOfGame();
					g = new Game();
					g->Init(m.chosenPathValue());
					this->Execute();
				}
				else if (sel == 2)// save game
				{
					ofstream fout("SavedLevel.txt", ofstream::out);
					fout << g->getCurrentLevel();
					fout.close();
				}
				if (sel == 3) // exit
				{
					g->ChangeState(GAME_OVER_GAME);
					break;
				}
			}
		}
		if (event.type == Event::Closed) {
			//Close the window, end the game...
			g->ChangeState(GAME_OVER_GAME);	
		}
	}
}
