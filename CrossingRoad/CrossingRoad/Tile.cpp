#include "Tile.h"
#include <Shlwapi.h>
#include <iostream>

Tile::Tile() : type(TREE), position({ 0,0,0,0 }), texture(nullptr) {}
Tile::Tile(TileType type, sf::Rect<objSize> position, std::string imgPath) : type(type),
position(position) {
	using namespace std;
	texture = new sf::Texture();
	if (!texture->loadFromFile(imgPath)) {
		cerr << "Tile.cpp Load anh co van de roi thang loz: " << imgPath << endl;
		delete texture;
		texture = nullptr;
		return;
	}
}

Tile::~Tile()
{
	delete texture;
	texture = nullptr;
}

Tile& Tile::operator=(const Tile& other)
{
	if (&other == this) return (*this);
	this->position = other.position;
	this->type = other.type;
	delete texture;
	using namespace sf;
	texture = new Texture();
	(*texture) = (*(other.texture));
	return (*this);
}

void Tile::SetTopLeftCoord(objSize _top, objSize _left)
{
	this->position.top = _top;
	this->position.left = _left;
}
