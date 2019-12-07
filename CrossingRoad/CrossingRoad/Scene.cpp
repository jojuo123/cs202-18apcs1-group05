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
				window.setFramerateLimit(60);
				g = new Game();
				g->Init(m.chosenPathValue(), savedLevel);
				sf::Vector2f centralP(g->columns / 2 * PIXEL_SIZE, g->rows * PIXEL_SIZE - SCREEN_HEIGHT / 2);
				sf::View view(centralP, sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
				window.setView(view);
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

void Scene::Update()
{
	g->UpdateObstaclesPosition();
	g->generateObject();
	UpdateCamera();
}

void Scene::Execute()
{
	
	if (g == NULL) return;
	//vector<vector<Tile> > Map = g->GetMap();
	while (g != nullptr) {
		HandleInput();
		if (g == NULL || g->isEndGame())
		{
			EndOfGame();
			break;
		}
		Update();
		Draw(g->Map);
		checkCollision();
		if (g == NULL || g->isEndGame())
		{
			EndOfGame();
			break;
		}
		else if (g->isEndGameByCollision())
		{
			EndOfGame();
			sf::Sprite * sp = m.GameOvermenu();
			window.clear();
			window.draw(*sp);
			window.display();
			sf::Event event;
			//wait for enter or escape pressed
			while (window.isOpen())
			{
				bool pause = 0;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::KeyReleased) {
						if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Escape)
							pause = 1;
					};	
				}
				if (pause == 1)
					break;
			}
			delete sp->getTexture();
			delete sp;
			//start new game
			this->Init();
			this->Execute();
			return;
		}
		else if (g->isLevelUp())
		{
			int  nextLevel = g->getCurrentLevel() + 1;
			EndOfGame();
			g = new Game();
			g->Init(m.chosenPathValue(), nextLevel);
			window.setFramerateLimit(60);
			sf::Vector2f centralP(g->columns / 2 * PIXEL_SIZE, g->rows * PIXEL_SIZE - SCREEN_HEIGHT / 2);
			sf::View view(centralP, sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
			window.setView(view);
		}
		
		
	}
	//if (g == NULL) std::cerr << "g == nullptr";
}

void Scene::Draw(vector<vector<Tile> > &Map)
{
	window.clear();
	//Draw all of g (Tiles, obstacles beforehand)
	DrawMap(Map);
	DrawLamp(g->lampList);
	for (int r = 0; r<g->rows; ++r)
		DrawObject(g->dqOb[r]);
	Draw(g->player);
	window.display();
}

void Scene::DrawMap(vector<vector<Tile> > &Map)
{
	for (int i = 0; i < Map.size(); ++i)
		for (int j = 0; j < Map[i].size(); ++j)
			Draw(Map[i][j]);
}
void Scene::DrawObject(deque<Object*> dqOb)
{
	deque<Object*> newdqOb;
	while (!dqOb.empty()) {
		Object *p = dqOb.front(); dqOb.pop_front();
		if (p->texture == nullptr) return;

		sf::Sprite sprite(*(p->texture));
		sprite.setPosition(p->position.left, p->position.top);
		if (p->dir == RIGHT)
			sprite.setTextureRect(sf::IntRect(sprite.getTextureRect().width,0, -sprite.getTextureRect().width, sprite.getTextureRect().height));
			//sprite.setScale(-1.f, 1.f);
		sf::Vector2f v =sprite.getPosition();
		window.draw(sprite);

		newdqOb.push_back(p);
	}
	dqOb = newdqOb;
}
void Scene::DrawLamp(vector<Lamp>& lampList)
{
	for (int i = 0; i < lampList.size(); ++i)
	{
		if (lampList[i].texture == NULL) continue;
		if (Object * obj = dynamic_cast<Object*>(&lampList[i]))
		{
			Draw(obj);
		}
		else
			cerr << "casting error" << endl;
	}
}
void Scene::UpdateCamera()
{
	//1. Deduct smallest row appear on screen (the top one)
	//Camera view: lowestTileRow -> lowestTileRow + numRowOnScreen - 1
	//NOTE: just access, call function later.
	int numRowOnScreen = SCREEN_HEIGHT / PIXEL_SIZE;
	int currentRow = g->player->coord.y;

	//2. DONOT SetTopLeftCoord those Tiles
	//Set sf::View instead
	sf::View view;
	view.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	//cerr << currentRow << " " << g->player->coord.x << endl;

	if (0 <= currentRow && currentRow < numRowOnScreen) {
		view.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	}
	else {
		sf::IntRect rct = g->player->getPosition();
		view.setCenter(SCREEN_WIDTH / 2, rct.top + rct.height - SCREEN_HEIGHT / 2);
	}
	window.setView(view);
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
void Scene::checkCollision()
{
	deque<Object*> dq = this->g->dqOb[g->player->coord.y];
	//deque<Object*> newdqOb;
	while (!dq.empty()) {
		Object *p = dq.front(); dq.pop_front();
		bool isHit = this->g->player->isHit(p);	
		if (isHit == 1)
		{
			g->ChangeState(GAME_OVER_COLLISION_GAME);			
			break;
		}
		//newdqOb.push_back(p);
	}
	//this->g->dqOb = newdqOb;
}
