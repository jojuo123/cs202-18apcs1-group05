#ifndef _LEVEL_H_
#define _LEVEL_H_


#include "Predefine.h"
#include <vector>

class Level
{
private:
	//int noOfRoad;
	//int noOfLanePerRoad;
	int LevelId;
	//int noOfDinoLane;
	//int noOfTigLane;
	//int noOfTruLane;
	//int noOfMotoLane;
	static const int levelListRoad[5];
	static const int levelListDinoLane[5];
	static const int levelListTigLane[5];
	static const int levelListTruckLane[5];
	static const int levelListMotoLane[5];
	static const int levelListGrassLane[5];
	static const float levelListDinoSpeed[5];
	static const float levelListTigSpeed[5];
	static const float levelListTruckSpeed[5];
	static const float levelListMotoSpeed[5];
	//2 row dau la grass
	//row cuoi grass
	
public:
	~Level() {}
	Level() = default;
	Level(int id) : LevelId(id) {}
	vector<ObjectType> getObstacle(); //random de tra ve list cac obs theo row
	int FinishLane() { return levelListRoad[LevelId - 1]; }
	float DinoSpeed() { return levelListDinoSpeed[LevelId - 1]; }
	float TigerSpeed() { return levelListTigSpeed[LevelId - 1]; }
	float TruckSpeed() { return levelListTruckSpeed[LevelId - 1]; }
	float MotorSpeed() { return levelListMotoSpeed[LevelId - 1]; }
	friend class Scene;
	friend class Game;
};


#endif // !

