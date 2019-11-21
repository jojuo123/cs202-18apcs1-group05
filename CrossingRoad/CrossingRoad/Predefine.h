#ifndef _PREDEFINE_
#define _PREDEFINE_

using namespace std;

#define objSize int
#define unitPerSecond int

struct Coord
{
	objSize x, y;
	Coord(objSize _x, objSize _y) : x(_x), y(_y) {}
	Coord() { x = y = 0; }
};


#endif // _PREDEFINE_

