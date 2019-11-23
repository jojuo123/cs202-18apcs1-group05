#include "Scene.h"

using namespace std;
Scene* Scene::sc = nullptr;
void Scene::Init() {
	int sel = m.StartMenu(window, menuFont);
	switch (sel)
	{
	case (MENU_EXIT): {
		cerr << "EXIT" << endl;
		break;
	}
	}
}
