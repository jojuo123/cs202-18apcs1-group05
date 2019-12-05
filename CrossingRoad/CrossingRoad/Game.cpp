#include "Game.h"

//Game* Game::instance = nullptr;

Obstacle* Obstacle::Create(ObjectType type, unitPerSecond _s, Coord _c, string texturePath, string soundPath, sf::Rect<objSize> _pos)
{
	if (type == DINOSAUR)
		return new Dinosaur(_s, _c, texturePath, soundPath, type, _pos);
	else if (type == TRUCK)
		return new Truck(_s, _c, texturePath, soundPath, type, _pos);
	else if (type == MOTOR)
		return new Motorbike(_s, _c, texturePath, soundPath, type, _pos);
	else if (type == TIGER)
		return new Tiger(_s, _c, texturePath, soundPath, type, _pos);
	else return nullptr;
}

void Game::StartGame()
{
	
}


void Game::Init(string chosenPath, int level)
{
	gameState = GAME_IN_GAME;
	score = 0;
	
	currentLevel = level;
	l = Level(currentLevel);
	InitTile();
	InitMap();
	player = new Player(0, { columns / 2, rows - 1 }, chosenPath, "sound/csdn.wav", PLAYER, { (columns / 2) * PIXEL_SIZE, (rows - 1) * PIXEL_SIZE ,64,64 });
}
void Game::InitTile()
{
	Grass1Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass.png");
	Grass2Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass1.png");
	Grass3Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass2.png");
	Grass4Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass3.png");

	FinishTile = Tile(FINISH, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/finish.png");

	RoadTile = Tile(ROAD, { 0,0,PIXEL_SIZE, PIXEL_SIZE }, "image/Road.png");
}

void Game::InitMap()
{
	
	rows = l.FinishLane() + 2;
	dqOb.resize(rows);
	vector<ObjectType> obj = l.getObstacle();
	while ((int)obj.size() < rows) obj.push_back(NONE);
	std::reverse(obj.begin(), obj.end());

	columns = (int)(ceil(SCREEN_WIDTH / PIXEL_SIZE));
	//Map = new Tile * [rows];
	//for (int i = 0; i < rows; i++) Map[i] = new Tile[columns];

	Map = vector<vector<Tile> >(rows, vector<Tile>(columns, Tile()));

	for (int i = 0; i < rows; ++i)
	{
		//if (i >= rows - 2) //2 lane cuoi
		//{
		//	//grass

		//	for (int j = 0; j < columns; ++j)
		//	{
		//		//set tile
		//		int rd = rand() % 4;
		//		//set position
		//		
		//	}
		//}
		//else 
		if (i == rows - 1 - l.FinishLane()) 
		{
			//finish line
			for (int j = 0; j < columns; ++j)
			{
				Map[i][j] = FinishTile;
				Map[i][j].SetTopLeftCoord(i * PIXEL_SIZE, j * PIXEL_SIZE);
			}
			spaceObs.push_back(-1);
		}
		else
		{
			AddTile(i, obj[i]);
			AddObject(i, obj[i]);
		}
	}
	for (int row = 0; row < spaceObs.size(); ++row)
		cerr << row << " " << spaceObs[row] << endl;
}

void Game::AddObject(int _row, ObjectType o)
{
	if (o != NONE)
	{
		int col = rand() % columns;
		Coord temp;
		Direction dir;
		if (col < 6)
		{
			dir = RIGHT;
			temp.x = col;
			temp.y = _row;
		}
		else if (col >= 6)
		{
			dir = LEFT;
			temp.x = col;
			temp.y = _row;
		}
		spaceObs.push_back(rand() % (columns-4 - 5+ 1) + 5);
		Obstacle *obs;
		int rdOpt = 0;
		switch (o)
		{
		case DINOSAUR:
			rdOpt = rand() % 2;
			if (rdOpt == 0)
				obs = Obstacle::Create(o, l.DinoSpeed(), temp, "image/dinosaur.gif", "sound/csdn", { col * PIXEL_SIZE, _row * PIXEL_SIZE, 2 * PIXEL_SIZE, PIXEL_SIZE });
			else 
				obs = Obstacle::Create(o, l.DinoSpeed(), temp, "image/dinosaur2.png", "sound/csdn", { col * PIXEL_SIZE, _row * PIXEL_SIZE, 2 * PIXEL_SIZE, PIXEL_SIZE });
			obs->setDirection(dir);
			dqOb[_row].push_front(obs);
			break;
		case TIGER:
			obs = Obstacle::Create(TIGER, l.TigerSpeed(), temp, "image/tiger.png", "sound/csdn", { col*PIXEL_SIZE, _row*PIXEL_SIZE,  2 * PIXEL_SIZE, PIXEL_SIZE });
			obs->setDirection(dir);
			dqOb[_row].push_front(obs);
			break;
		case MOTOR:
			rdOpt = rand() % 2;
			if (rdOpt == 0)
				obs = Obstacle::Create(MOTOR, l.MotorSpeed(), temp, "image/motor.png", "sound/csdn", { col*PIXEL_SIZE, _row*PIXEL_SIZE, 2 * PIXEL_SIZE, PIXEL_SIZE });
			else 
				obs = Obstacle::Create(MOTOR, l.MotorSpeed(), temp, "image/motor2.png", "sound/csdn", { col * PIXEL_SIZE, _row * PIXEL_SIZE, 2 * PIXEL_SIZE, PIXEL_SIZE });
			obs->setDirection(dir);
			dqOb[_row].push_front(obs);
			break;
		case TRUCK:
			rdOpt = rand() % 2;
			if (rdOpt == 0)
				obs = Obstacle::Create(TRUCK, l.TruckSpeed(), temp, "image/truck.png", "sound/csdn", { col*PIXEL_SIZE, _row*PIXEL_SIZE, 2 * PIXEL_SIZE, PIXEL_SIZE });
			else 
				obs = Obstacle::Create(TRUCK, l.TruckSpeed(), temp, "image/truck2.png", "sound/csdn", { col * PIXEL_SIZE, _row * PIXEL_SIZE, 2 * PIXEL_SIZE, PIXEL_SIZE });
			obs->setDirection(dir);
			dqOb[_row].push_front(obs);
			break;
		}
	}
	else spaceObs.push_back(-1);
}


void Game::AddTile(int _row, ObjectType o)
{	
	for (int j = 0; j < columns; ++j)
	{
		if (o == NONE)
		{
			int rd = rand() % 4;
			switch (rd)
			{
			case 0:
				Map[_row][j] = Grass1Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
				break;
			case 1:
				Map[_row][j] = Grass2Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
				break;
			case 2:
				Map[_row][j] = Grass3Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
				break;
			case 3:
				Map[_row][j] = Grass4Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
				break;
			}
		}
		else
		{
			Map[_row][j] = RoadTile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
		}
	}
}

bool Game::isEndGame()
{
	return (gameState == GAME_OVER_GAME );
}
bool Game::isLevelUp()
{
	return(player->coord.y <= rows - 1 - l.FinishLane() && l.getLevelId() <= GAME_MAX_LEVEL);
}
bool Game::isEndGameByCollision()
{
	return (gameState == GAME_OVER_COLLISION_GAME);
}
void Game::ChangeState(int state)
{
	gameState = state;
}

void Game::HandlePlayerInput(int input)
{
	Coord c = player->coord;
	switch (input) {
	case PLAYERINPUT_MOVEDOWN: {
		if (c.y+1<rows)
			player->Move(DOWN, 64);
		break;
	}
	case PLAYERINPUT_MOVELEFT: {
		if (c.x-1>=-columns/2)
			player->Move(LEFT, 32);
		break;
	}
	case PLAYERINPUT_MOVEUP: {
		if (c.y-1>=0)
			player->Move(UP, 64);
		break;
	}
	case PLAYERINPUT_MOVERIGHT: {
		if (c.x+1<columns+columns/2)
			player->Move(RIGHT, 32);
		break;
	}
	}
}
void Game::UpdateObstaclesPosition()
{
	for (int r = 0; r < rows; ++r) {
		deque<Object*> &dq = dqOb[r];
		deque<Object*> newdqOb;
		while (!dq.empty()) {
			Object *p = dq.front(); dq.pop_front();
			p->UpdatePosition();
			if (p->isOutOfScreen()) { //p is out of screen
				delete p;
			}
			else newdqOb.push_back(p);
		}
		dq = newdqOb;
	}
}
void Game::generateObject()
{
	for (int row = 0; row < this->dqOb.size(); ++row)
	{
		if (!dqOb[row].empty())
		{
			Object* lastObj = dqOb[row].back();
			if (!lastObj->isOutOfScreen())
			{
				Object * newLastObj = new Obstacle;
				*newLastObj = *lastObj;
				sf::Rect<objSize> position = lastObj->getPosition();
				if(newLastObj->getDirection() == RIGHT)
					position.left = lastObj->getPosition().left - spaceObs[row] * PIXEL_SIZE;
				else if(newLastObj->getDirection() == LEFT)
					position.left = lastObj->getPosition().left + spaceObs[row] * PIXEL_SIZE;
				newLastObj->setPosition(position);
				dqOb[row].push_back(newLastObj);
				//cerr <<row<<" "<< spaceObs[row] << endl;
			}
		}
	}
}