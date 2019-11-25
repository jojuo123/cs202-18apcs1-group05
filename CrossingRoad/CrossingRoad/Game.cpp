#include "Game.h"

Game* Game::instance = nullptr;

void Game::StartGame()
{
	
}

void Game::Init()
{
	score = 0;
	player = new Player(0, { 3,5 }, "player.png", "csdn.wav", PLAYER, { 100,100,64,64 });
}

void Game::HandlePlayerInput(int input)
{
	switch (input) {
	case PLAYERINPUT_MOVEDOWN: {
		player->Move(DOWN, 64);
		break;
	}
	case PLAYERINPUT_MOVELEFT: {
		player->Move(LEFT, 64);
		break;
	}
	case PLAYERINPUT_MOVEUP: {
		player->Move(UP, 64);
		break;
	}
	case PLAYERINPUT_MOVERIGHT: {
		player->Move(RIGHT, 64);
		break;
	}
	}
}
