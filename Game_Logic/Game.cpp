#include "Game.h"

Game::Game() {
	manager = ObjectManager();
	factory = new ObjectFactory(manager);
}
Game::~Game() {
	delete factory;
}
