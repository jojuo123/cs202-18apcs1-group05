#include "Game.h"

//Game* Game::instance = nullptr;

Obstacle* Obstacle::Create(ObjectType type, unitPerSecond _s, Coord _c, string texturePath, string soundPath, ObjectType _t, sf::Rect<objSize> _pos)
{
	if (type == DINOSAUR)
		return new Dinosaur(_s, _c, texturePath, soundPath, _t, _pos);
	else if (type == TRUCK)
		return new Truck(_s, _c, texturePath, soundPath, _t, _pos);
	else if (type == MOTOR)
		return new Motorbike(_s, _c, texturePath, soundPath, _t, _pos);
	else if (type == TIGER)
		return new Tiger(_s, _c, texturePath, soundPath, _t, _pos);
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
	vector<ObjectType> obj = l.getObstacle();
	while (obj.size() < rows) obj.push_back(NONE);
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
		}
		else
		{
			AddTile(i, obj[i]);
			AddObject(i, obj[i]);
		}
	}
}

void Game::AddObject(int _row, ObjectType o)
{
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
	return (gameState == GAME_OVER_GAME || player->coord.y >= rows - 1 - l.FinishLane());
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
		if (c.x-1>=0)
			player->Move(LEFT, 64);
		break;
	}
	case PLAYERINPUT_MOVEUP: {
		if (c.y-1>=0)
			player->Move(UP, 64);
		break;
	}
	case PLAYERINPUT_MOVERIGHT: {
		if (c.x+1<columns)
			player->Move(RIGHT, 64);
		break;
	}
	}
}
