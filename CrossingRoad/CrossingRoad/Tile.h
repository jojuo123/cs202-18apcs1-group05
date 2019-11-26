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
	Tile() = default;
	Tile(TileType _type, sf::Rect<objSize> _position, std::string texturePath) : type(_type), position(_position)
	{
		using namespace std;
		texture = new sf::Texture;
		if (!texture->loadFromFile(texturePath)) {
			cerr << "ko the load hinh: " << texturePath << endl;
			delete texture;
			texture = nullptr;
		}
	}

	Tile& operator= (const Tile& other);

	void SetTopLeftCoord(objSize, objSize);

	~Tile()
	{
		delete texture;
		texture = nullptr;
	}
};

#endif // !_TILE_H_

