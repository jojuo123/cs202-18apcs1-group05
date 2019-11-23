#include "Menu.h"
using namespace std;

int Menu::StartMenu(sf::RenderWindow &window, sf::Font &font) {
	using namespace sf;

	sf::String txt[4] = { "Start Game", "Load Game", "Settings", "Exit" };
	sf::Vector2f txtPos[4] = {
		{50, 50},
	{50,80}, {50, 120}, {50, 150}
	};
	sf::Text db[4][2];
	const int nSelect = 4;
	for (int i = 0; i < nSelect; ++i) {
		db[i][0].setFont(font);
		db[i][0].setString(txt[i]);
		db[i][0].setPosition(txtPos[i]);
		db[i][1].setFont(font);
		db[i][1].setString(txt[i]);
		db[i][1].setFillColor(sf::Color(255, 255, 0));
		db[i][1].setPosition(txtPos[i]);
	}
	int sel = 0;
	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == Event::KeyPressed) {
				switch (ev.key.code) {
				case (Keyboard::Up): {
					sel--;
					if (sel < 0) sel += nSelect;
					break;
				}
				case (Keyboard::Down): {
					sel++;
					sel %= nSelect;
					break;
				}
				case (Keyboard::Enter): {
					return sel;
				}
				}
			}
		}
		window.clear();
		for (int i=0; i<nSelect; ++i)
			if (i == sel)
				window.draw(db[i][1]);
			else window.draw(db[i][0]);
			
		window.display();
	}
	return 0;
}

int Menu::PauseMenu() {
	return 1;
}


