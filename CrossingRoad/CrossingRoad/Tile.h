#ifndef _TILE_H_
#define _TILE_H_

#include "Predefine.h"
#include <string>
#include<iostream>
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
	Tile(TileType _type, sf::Rect<objSize> _position, std::string texturePath);

	Tile& operator= (const Tile& other);

	void SetTopLeftCoord(objSize, objSize);

	~Tile();

};

#endif // !_TILE_H_

