#include "Game.h"

Game::Game() {
	manager = new ObjectManager();
	generator = new ObjectGenerator(this);
}
Game::~Game() {}

void Game::Initialize() {
	manager->ResolveStack();
}

void Game::Update() {
	manager->Update();
}

void Game::Destroy(GameObject* obj) {
	manager->RemoveObject(obj);
}

GameObject* Game::Instantiate(const TYPE& t, const Vector& position) {
	GameObject* obj = generator->Instantiate(t, position);
	manager->AddObject(obj);
	return obj;
}
