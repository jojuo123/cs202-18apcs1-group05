#include "Game.h"

//Game* Game::instance = nullptr;

void Game::StartGame()
{
	
}


void Game::Init(string chosenPath, int level)
{
	gameState = GAME_IN_GAME;
	score = 0;
	player = new Player(0, { 3,5 }, chosenPath, "sound/csdn.wav", PLAYER, { 100,100,64,64 });
	currentLevel = level;
	l = Level(currentLevel);
	InitTile();
	InitMap();
}
void Game::InitTile()
{
	Grass1Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass.png");
	Grass2Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass1.png");
	Grass3Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass2.png");
	Grass4Tile = Tile(GRASS, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/grass3.png");

	FinishTile = Tile(FINISH, { 0, 0, PIXEL_SIZE, PIXEL_SIZE }, "image/finish.png");

	RoadTile = Tile(ROAD, { 0,0,PIXEL_SIZE, PIXEL_SIZE }, "image/road.png");
}

void Game::InitMap()
{
	
	rows = l.FinishLane() + 10;
	vector<ObjectType> obj = l.getObstacle();
	while (obj.size() < rows) obj.push_back(NONE);
	std::reverse(obj.begin(), obj.end());

	columns = (int)(ceil(SCREEN_WIDTH / PIXEL_SIZE) + 1);
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
		if (i == rows - 1 + l.FinishLane()) 
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
	if (o == NONE)
	{
		int rd = rand() % 4;
		switch (rd) {
		case 0:
			for (int j = 0; j < columns; ++j) Map[_row][j] = Grass1Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
			break;
		case 1:
			for (int j = 0; j < columns; ++j) Map[_row][j] = Grass2Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
			break;
		case 2:
			for (int j = 0; j < columns; ++j) Map[_row][j] = Grass3Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
			break;
		case 3:
			for (int j = 0; j < columns; ++j) Map[_row][j] = Grass4Tile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
			break;
		}
	}
	else 
	{
		for (int j = 0; j < columns; ++j)
			Map[_row][j] = RoadTile, Map[_row][j].SetTopLeftCoord(_row * PIXEL_SIZE, j * PIXEL_SIZE);
	}
}

bool Game::isEndGame()
{
	return (gameState == GAME_OVER_GAME || score == l.FinishLane());
}

void Game::ChangeState(int state)
{
	gameState = state;
}

void Game::HandlePlayerInput(int input)
{
	switch (input) {
	case PLAYERINPUT_MOVEDOWN: {
		player->Move(DOWN, 64);
		break;
	}
	case PLAYERINPUT_MOVELEFT: {
		player->Move(LEFT, 64);
		break;
	}
	case PLAYERINPUT_MOVEUP: {
		player->Move(UP, 64);
		break;
	}
	case PLAYERINPUT_MOVERIGHT: {
		player->Move(RIGHT, 64);
		break;
	}
	}
}
