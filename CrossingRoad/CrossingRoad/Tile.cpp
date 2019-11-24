#include "Tile.h"
#include <Shlwapi.h>
#include <iostream>

Tile::Tile() : type(TREE), position({ 0,0,0,0 }), texture(nullptr) {}
Tile::Tile(TileType type, sf::Rect<objSize> position, std::string imgPath) : type(type),
position(position) {
	using namespace std;
	texture = new sf::Texture();
	if (!texture->loadFromFile(imgPath)) {
		cerr << "Load anh co van de roi thang loz: " << imgPath << endl;
		delete texture;
		texture = nullptr;
		return;
	}
}

Tile::~Tile()
{
	delete texture;
}
