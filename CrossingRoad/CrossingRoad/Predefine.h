#ifndef _PREDEFINE_
#define _PREDEFINE_

#include <Windows.h>
#include <SFML/System.hpp>

using namespace std;

#define objSize int
#define unitPerSecond int
#define START_MENU 1
#define ON_GAME_RUNNING 2
#define PAUSE_GAME 3

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
sf::String SCREEN_TITLE = "Viet cong muon nam";

struct Coord
{
	objSize x, y;
	Coord(objSize _x, objSize _y) : x(_x), y(_y) {}
	Coord() { x = y = 0; }
};

void GoToXY(int, int);


#endif // _PREDEFINE_

