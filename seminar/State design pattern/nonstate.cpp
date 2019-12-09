#include<iostream>
using namespace std;
enum STATE {HAPPY,ANGRY,SAD};
enum ACTION{IGNORE,PLAY,POKE};
class dog
{
private:
	STATE s;
public:
	dog() {
		s = HAPPY;
	}
	void doAction(ACTION);
};

void dog::doAction(ACTION a) {
		if (a == IGNORE) {
			if (s == HAPPY){
				s = SAD;
				cout << "Happy to sad.";
			}
			else if (s == SAD)
				cout << "Sad x2.";
			else if (s == ANGRY)
				cout << "Keep Angry";
		}
		else if (a == PLAY) {
			if (s == HAPPY)
				cout << "Happy x2";
			else if (s == ANGRY){
				s = HAPPY;
				cout << "Angry to happy";
			}
			else if (s == SAD){
				s = HAPPY;
				cout << "Sad to happy";
			}
		}
		else if (a == POKE) {
			if (a == HAPPY){
				s = ANGRY;
				cout << "Happy to angry";
			}
			else if (a == SAD){
				s = ANGRY;
				cout << "Sad to angry";
			}
			else if (s == ANGRY)
				cout << "Angry x2";
		}
}
