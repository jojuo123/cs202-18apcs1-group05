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
void Scene::Draw(const Tile &tile)
{
	if (tile.texture == nullptr) return;
	sf::Sprite sprite(*(tile.texture));
	sprite.setPosition(tile.position.left, tile.position.top);
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
		sf::Vector2f centralP(g->columns / 2 * PIXEL_SIZE, g->rows * PIXEL_SIZE - SCREEN_HEIGHT / 2);
		sf::View view(centralP, sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		window.setView(view);
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
	
	if (g == NULL) return;
	//vector<vector<Tile> > Map = g->GetMap();
	while (g != nullptr) {
		HandleInput();
		if (g->isEndGame())
		{
			EndOfGame();
			break;
		}
		Draw(g->Map);
	}
	//if (g == NULL) std::cerr << "g == nullptr";
}

void Scene::Draw(vector<vector<Tile> > &Map)
{
	window.clear();
	//Draw all of g (Tiles, obstacles beforehand)
	DrawMap(Map);

	Draw(g->player);
	window.display();
}

void Scene::DrawMap(vector<vector<Tile> > &Map)
{
	for (int i = 0; i < Map.size(); ++i)
		for (int j = 0; j < Map[i].size(); ++j)
			Draw(Map[i][j]);
}

void Scene::UpdateCamera()
{
	//1. Deduct lowest row appear on screen
	//Camera view: lowestTileRow -> lowestTileRow + numRowOnScreen - 1
	//NOTE: just access, call function later.
	int numRowOnScreen = SCREEN_HEIGHT / PIXEL_SIZE;
	int lowestTileRow;
	if (g->player->coord.y + numRowOnScreen - 1 >= g->rows) {
		lowestTileRow = g->rows - numRowOnScreen + 1;
		if (lowestTileRow < 0) lowestTileRow = 0;
	}
	else {
		lowestTileRow = g->player->coord.y;
	}

	//2. SetTopLeftCoord those Tiles
	for (int i=0; i<g->rows; ++i)
		if (lowestTileRow <= i && i <= lowestTileRow + numRowOnScreen - 1) {
			int positiveRowPos = (i - lowestTileRow)*PIXEL_SIZE;
			int rowTopPos = SCREEN_HEIGHT - positiveRowPos - PIXEL_SIZE;
			for (int j = 0; j < g->columns; ++j)
				g->Map[i][j].SetTopLeftCoord(rowTopPos, j*PIXEL_SIZE);
		}
		else {
			for (int j = 0; j < g->columns; ++j)
				g->Map[i][j].SetTopLeftCoord(-1000, -1000);
		}
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
