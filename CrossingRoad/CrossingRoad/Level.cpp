#include "Level.h"

const int Level::levelListRoad[5] = {
	5, 10, 15, 20, 25
};
Level::Level(int id)
{
	noOfRoad = 10;
}

vector<ObjectType> Level::getObstacle()
{
	return vector<ObjectType>();
}
