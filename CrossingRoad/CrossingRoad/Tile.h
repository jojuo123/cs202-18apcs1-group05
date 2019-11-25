#ifndef _TILE_H_
#define _TILE_H_

#include "Predefine.h"

using namespace sf;

class Tile
{
private:
	TileType type;
	Rect<objSize> position;
	Texture* texture;
public:
	friend class Scene;
};

#endif // !_TILE_H_

