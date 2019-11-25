#ifndef _PREDEFINE_
#define _PREDEFINE_


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>

using namespace std;

#define objSize int
#define unitPerSecond int
#define MENU_STARTGAME 0
#define MENU_LOADGAME 1
#define MENU_SETTING 2
#define MENU_EXIT 3
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//sf::String SCREEN_TITLE = "Viet cong muon nam";

enum TileType { GRASS, WATER, ROAD, RAIL, TREE };
enum ObjectType { PLAYER, MOTOR, TRUCK, STICK, LAMP, TIGER, DINOSAUR };
enum GameState { START, PLAY, EXITE, PAUSE, GAME_OVER, OUT_OF_GAME, CHOOSE_PLAYER };
enum Direction { UP, DOWN, LEFT, RIGHT };

struct Coord
{
	objSize x, y;
	Coord(objSize _x, objSize _y) : x(_x), y(_y) {}
	Coord() { x = y = 0; }
};

void GoToXY(int, int);


#endif // _PREDEFINE_

