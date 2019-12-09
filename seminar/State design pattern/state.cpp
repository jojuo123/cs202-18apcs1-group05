#include <iostream>

using namespace std;

class State;

class CyberDog {
public:
	void play();
	void ignore();
	void poke();
	CyberDog();
	~CyberDog();
private:
	friend class State;
	void ChangeState(State* newState);
private:
	State *curState;
};

class State {
public:
	virtual void play(CyberDog *dog) {}
	virtual void ignore(CyberDog *dog) {}
	virtual void poke(CyberDog *dog) {}
protected:
	void ChangeState(CyberDog *dog, State * newState) {
		dog->ChangeState(newState);
	}
};


void CyberDog::play() { 
	curState->play(this); 
}
void CyberDog::ignore() { 
	curState->ignore(this); 
}
void CyberDog::poke() {
	curState->poke(this);
}
CyberDog::~CyberDog() {
	delete this->curState;
}
void CyberDog::ChangeState(State * newState) {
	delete curState;
	this->curState = newState;
}


class StateFun;
class StateAngry;
class StateSad;

class StateFun : public State {
public:
	void play(CyberDog *dog);
	void poke(CyberDog *dog);
	void ignore(CyberDog *dog);
};

class StateSad : public State {
public:
	void play(CyberDog *dog);
	void poke(CyberDog *dog);
	void ignore(CyberDog *dog);
};
class StateAngry : public State {
public:
	void play(CyberDog *dog);
	void poke(CyberDog *dog);
	void ignore(CyberDog *dog);
};

int main() {
	CyberDog test;
	test.play();
	test.ignore();
	test.play();
	test.poke();
	test.play();
	return 0;
}

CyberDog::CyberDog() {
	curState = new StateFun();
}

void StateFun::play(CyberDog * dog) {
	cout << "Happy x2\n";
}

void StateFun::poke(CyberDog * dog) {
	cout << "Happy to angry\n";
	ChangeState(dog, new StateAngry());
}

void StateFun::ignore(CyberDog * dog) {
	cout << "Happy to sad\n";
	ChangeState(dog, new StateSad());
}

void StateSad::play(CyberDog * dog) {
	cout << "Sad to happy\n";
	ChangeState(dog, new StateFun());
}

void StateSad::poke(CyberDog * dog) {
	cout << "Sad to angry\n";
	ChangeState(dog, new StateAngry());
}

void StateSad::ignore(CyberDog * dog) {
	cout << "Sad x2\n";
}

void StateAngry::play(CyberDog * dog) {
	cout << "Angry to happy\n";
	ChangeState(dog, new StateFun());
}

void StateAngry::poke(CyberDog * dog) {
	cout << "Angry x2\n";
}

void StateAngry::ignore(CyberDog * dog) {
	cout << "Keep angry\n";
	ChangeState(dog, new StateAngry());
}
