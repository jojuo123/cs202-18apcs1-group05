#include "Menu.h"
using namespace std;

int Menu::StartMenu(sf::RenderWindow &window, sf::Font &font) {
	window.clear();
	sf::Text tx1("Start Game", font, 30);
	tx1.setPosition({ 50, 50 });
	sf::Text tx2("Load Game", font, 30);
	tx2.setPosition({ 50, 80 });
	sf::Text tx3("Settings", font, 30);
	tx3.setPosition({ 50, 120 });
	sf::Text tx4("Exit", font, 30);
	tx4.setPosition({ 50,150 });
	window.draw(tx1);
	window.draw(tx2);
	window.draw(tx3);
	window.draw(tx4);
	window.display();
}

int Menu::PauseMenu() {

}



