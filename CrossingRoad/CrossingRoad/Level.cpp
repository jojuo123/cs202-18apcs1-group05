#include "Level.h"

const int Level::levelListRoad[5] = {
	10, 15, 20, 25, 30
};
const int Level::levelListDinoLane[5] = {0,3,0,0,0};
const int Level::levelListTigLane[5] = { 2,3,0,0,27 };
const int Level::levelListTruckLane[5] = { 2,3,0,22,0 };
const int Level::levelListMotoLane[5] = { 2,3,17,0,0 };
const int Level::levelListGrassLane[5] = { 4,3,3,3,3 };

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
	random_shuffle(rowLane.begin() + 2, rowLane.begin() + ccgido);
	return rowLane;
}
