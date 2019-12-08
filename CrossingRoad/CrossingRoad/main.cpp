#include <iostream>
//#include <SDL.h>
//#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace std;

//#define _TEST_

#ifdef _TEST_
class Base
{
public:
	virtual void print() { cout << "Base"; }
};
class Derived : public Base
{
public:
	virtual void print() { cout << "Derived"; }
};
void test()
{
	Derived d;
	d.print();
	Base* b = dynamic_cast<Base*>(&d);
	b->print();
	delete b;
	try
	{
		d.print();
	}
	catch (const std::exception& e)
	{
		cerr << endl << e.what();
	}
}
#endif

int main(int argc, char *argv[])
{
#ifdef _TEST_
	test();
#else
	srand(time(NULL));
	Scene *sc = Scene::getInstance();
	sc->Init();
	sc->Execute();

	delete sc;
#endif
	return 0;
}