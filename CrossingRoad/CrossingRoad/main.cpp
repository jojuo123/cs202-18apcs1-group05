#include <iostream>
//#include <SDL.h>
//#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace std;

string to_string(ObjectType obj) {
	switch (obj) {
	case(TIGER): return "tiger";
	case(DINOSAUR): return "dinosaur";
	case(TRUCK): return "truck";
	case(MOTOR): return "motor";
	case(NONE): return "none";
	}
}
string to_string(vector<ObjectType> obj) {
	string ans = "";
	for (ObjectType o : obj) ans += to_string(o) + " ";
	return ans;
}
void test() {
	Level lvl(1);
	for (int runTime = 1; runTime <= 4; ++runTime) {
		vector<ObjectType> obj = lvl.getObstacle();
		cout << to_string(obj) << endl;
	}
}

int main(int argc, char *argv[])
{/*
	Scene *sc = Scene::getInstance();
	sc->Init();
	sc->Execute();
	delete sc;*/
	test();
	return 0;
}