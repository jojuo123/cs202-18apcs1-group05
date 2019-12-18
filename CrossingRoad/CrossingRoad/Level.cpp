#include "Level.h"
#include <algorithm>

const int Level::levelListRoad[5] = {
	11, 17, 28, 32, 38
};
const int Level::levelListDinoLane[5] = {1,3,0,2,3};
const int Level::levelListTigLane[5] = { 2,3,0,0,27 };
const int Level::levelListTruckLane[5] = { 2,3,0,22,0 };
const int Level::levelListMotoLane[5] = { 2,3,17,0,0 };
const int Level::levelListGrassLane[5] = { 4,5,8,8,8 };

const float Level::levelListDinoSpeed[5] = { 71, 87, 99,115, 135 };
const float Level::levelListTigSpeed[5] = { 61, 75, 85, 120, 124 };
const float Level::levelListTruckSpeed[5] = { 100, 150, 170, 190, 222 };
const float Level::levelListMotoSpeed[5] = { 120, 149, 150, 165, 190 };

const int Level::levelListMaxRedTimer[5] = { 7, 7, 6, 5, 4 };
const int Level::levelListMinRedTimer[5] = { 1, 1, 1, 1, 1 };
const int Level::levelListMaxGreenTimer[5] = { 6, 6, 5, 4, 4};
const int Level::levelListMinGreenTimer[5] = { 1, 2, 1, 1, 1 };

vector<ObjectType> Level::getObstacle()
{
	vector<ObjectType> rowLane;
	int lvlid = LevelId - 1;
	for (int i = 0; i < levelListGrassLane[lvlid]-1; ++i)
		rowLane.push_back(NONE);
	for (int i = 0; i < levelListTigLane[lvlid]; ++i) rowLane.push_back(TIGER);
	for (int i = 0; i < levelListTruckLane[lvlid]; ++i) rowLane.push_back(TRUCK);
	for (int i = 0; i < levelListMotoLane[lvlid]; ++i) rowLane.push_back(MOTOR);
	for (int i = 0; i < levelListDinoLane[lvlid]; ++i) rowLane.push_back(DINOSAUR);
	rowLane.push_back(NONE);

	int ccgido = (int)rowLane.size() - 1;
	std::random_shuffle(rowLane.begin() + 2, rowLane.begin() + ccgido);
	return rowLane;
}
