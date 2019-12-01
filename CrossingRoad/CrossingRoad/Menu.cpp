#include "Menu.h"
using namespace std;
const string Menu::path[5] = {
	"image/skin1.png",
	"image/skin2.png",
	"image/skin3.png",
	"image/skin4.png",
	"image/skin5.png",
};

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
	window.setView(window.getDefaultView()); //SET DEFAULT VIEW BACK DUE TO GAME
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



int Menu::PauseMenu(sf::RenderWindow  &window, sf::Font &font) {
	sf::Text text;
	text.setFont(font);
	text.setString("PAUSE MENU");
	text.setFillColor(sf::Color(200, 100, 20));
	text.setPosition(5, 5);
	text.setScale(3, 3);
	sf::String txt[4] = { "Continue", "Restart", "Save Game", "Exit" };
	sf::Vector2f txtPos[4] = {
		{50, 120},
	{50,150}, {50, 180}, {50, 210}
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
	window.setView(window.getDefaultView()); //SET DEFAULT VIEW BACK DUE TO GAME
	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::KeyPressed) {
				switch (ev.key.code) {
				case (sf::Keyboard::Up): {
					sel--;
					if (sel < 0) sel += nSelect;
					break;
				}
				case (sf::Keyboard::Down): {
					sel++;
					sel %= nSelect;
					break;
				}
				case (sf::Keyboard::Enter): {
					return sel;
				}
				}
			}
		}
		window.clear();
		window.draw(text);
		for (int i = 0; i < nSelect; ++i)
			if (i == sel)
				window.draw(db[i][1]);
			else window.draw(db[i][0]);

		window.display();
	}
	return 0;
}

int Menu::SettingMenu(sf::RenderWindow & window, sf::Font & font)
{
	
	
	
	const int size =120;
	
	
	sf::Text text;
	text.setFont(font);
	text.setString("SETTING MENU");
	text.setFillColor(sf::Color(200, 100, 20));
	text.setPosition(5, 5);
	text.setScale(3, 3);

	sf::String txt[2] = { "Character skin","Sound"};
	sf::Vector2f txtPos[2] = {
		{50,120},
	{50,250}
	};

	sf::Text db[2][2];
	const int nSelect =2;
	for (int i = 0; i < nSelect; ++i) {
		db[i][0].setFont(font);
		db[i][0].setString(txt[i]);
		db[i][0].setPosition(txtPos[i]);
		db[i][1].setFont(font);
		db[i][1].setString(txt[i]);
		db[i][1].setFillColor(sf::Color(255, 255, 0));
		db[i][1].setPosition(txtPos[i]);
	}
	//sound mode
	sf::String soundMode[2] = { "OFF","ON" };
	sf::Vector2f soundModePos = { 450,250};
	sf::Text soundModeText[2][2];
	for (int i = 0; i < 2; ++i)
	{
		soundModeText[i][0].setFont(font);
		soundModeText[i][0].setString(soundMode[i]);
		soundModeText[i][0].setPosition(soundModePos);
		soundModeText[i][1].setFont(font);
		soundModeText[i][1].setString(soundMode[i]);
		soundModeText[i][1].setFillColor(sf::Color(255, 255, 0));
		soundModeText[i][1].setPosition(soundModePos);
	}
	int ImgSel = 0;
	int SoundSel = this->sound; //sound selected
	int sel = 0;
	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::KeyPressed) {
				switch (ev.key.code) {

				case (sf::Keyboard::Up): {
					sel--;
					if (sel < 0) sel += nSelect;
					break;
				}
				case (sf::Keyboard::Down): {
					sel++;
					sel %= nSelect;
					break;
				}
				case (sf::Keyboard::Right):
				{
					if (sel == 0)
					{
						ImgSel++;
						if (ImgSel == 5)
						{
							ImgSel = 0;
						}
					}
					else if (sel == 1)
					{
						if (SoundSel == 0)
							SoundSel = 1;
						else SoundSel = 0;
					}

					break;
				}
				case (sf::Keyboard::Left):
				{
					if (sel == 0)
					{
						ImgSel--;
						if (ImgSel < 0)
						{
							ImgSel = 4;
						}
					}
					else if (sel == 1)
					{
						if (SoundSel == 0)
							SoundSel = 1;
						else SoundSel = 0;
					}
					break;
				}
				case (sf::Keyboard::Escape): {
					this->chosenPath = path[ImgSel];
					this->sound = (SoundSel == 1) ?  true : false;
					return sel;
				}
				}
			}
		}
		window.clear();
		window.draw(text);

		sf::Texture texture;
		sf::Sprite sprite;
		sprite.setPosition(430, 100);
		if (texture.loadFromFile(path[ImgSel]))
		{
			sf::Vector2u v = texture.getSize();
			float scaleX = size / (float)v.x;
			float scaleY = size / (float)v.y;
			sprite.setScale(scaleX, scaleY);
			sprite.setTexture(texture);
			window.draw(sprite);
		}
		
		for (int i = 0; i < nSelect; ++i)
			if (i == sel)
			{
				window.draw(db[i][1]);
				if (sel == 1)
				{
					window.draw(soundModeText[SoundSel][1]);
				}
			}
			else
			{
				window.draw(db[i][0]);
				if (sel != 1)
					window.draw(soundModeText[SoundSel][0]);
			}
		window.display();
	}

	return 0;
}

sf::Sprite* Menu::GameOvermenu()
{
	sf::Texture *texture = new sf::Texture;
	if (!texture->loadFromFile(gameOverScreenPath))
	{
		cerr<< " cant load game over screen image";
	}

	sf::Sprite* sp = new sf::Sprite;
	sp->setTexture(*texture);
	sf::Vector2u v = texture->getSize();
	float scaleX = SCREEN_WIDTH / (float)v.x;
	float scaleY = SCREEN_HEIGHT / (float)v.y;
	sp->setScale(scaleX, scaleY);
	sp->setPosition(0, 0);
	return sp;
}



