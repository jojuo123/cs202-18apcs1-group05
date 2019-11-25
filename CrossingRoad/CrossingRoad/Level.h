#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Object.h"
#include "Predefine.h"
#include "Obstacle.h"
#include "Vehicle.h"
#include "Animal.h"
#include "Dinosaur.h"
#include "Truck.h"
#include "Motorbike.h"
#include "Tiger.h"
#include <vector>

class Level
{
private:
	int noOfRoad;
	int noOfLanePerRoad;
	int LevelId;
	int noOfDinoLane;
	int noOfTigLane;
	int noOfTruLane;
	int noOfMotoLane;
	static const int levelListRoad[5];
public:
	~Level() {}
	Level() = default;
	Level(int id);
	vector<ObjectType> getObstacle(); //random de tra ve list cac obs theo row
	int FinishLane() { return noOfRoad; }
	friend class Scene;
	friend class Game;
};


#endif // !

