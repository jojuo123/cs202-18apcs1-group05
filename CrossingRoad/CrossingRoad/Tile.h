#ifndef _TILE_H_
#define _TILE_H_

#include "Predefine.h"
#include <string>

//using namespace sf; IT'S NOT GOOD M8

class Tile
{
private:
	TileType type;
	sf::Rect<objSize> position;
	sf::Texture* texture;
public:
	friend class Scene;
	Tile();
	Tile(TileType type, sf::Rect<objSize> position, std::string imgPath);
	~Tile();
};

#endif // !_TILE_H_

