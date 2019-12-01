#ifndef _PREDEFINE_
#define _PREDEFINE_


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <Windows.h>

using namespace std;

#define objSize int

#define unitPerSecond int

#define MENU_STARTGAME 0
#define MENU_LOADGAME 1
#define MENU_SETTING 2
#define MENU_EXIT 3

#define SCREEN_WIDTH 832 //64x13
#define SCREEN_HEIGHT 640 //64x10

#define PLAYERINPUT_MOVEUP 30
#define PLAYERINPUT_MOVEDOWN 04
#define PLAYERINPUT_MOVELEFT 45
#define PLAYERINPUT_MOVERIGHT 1975

#define GAME_IN_GAME 1
#define GAME_PAUSE_GAME 2
#define GAME_OVER_GAME 3
#define GAME_OVER_COLLISION_GAME 4

#define PIXEL_SIZE 64

//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//sf::String SCREEN_TITLE = "Viet cong muon nam";

enum TileType { GRASS, WATER, ROAD, RAIL, TREE, FINISH };
enum ObjectType { PLAYER, MOTOR, TRUCK, STICK, LAMP, TIGER, DINOSAUR, NONE };
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

