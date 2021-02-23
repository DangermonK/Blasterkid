#include "Game.h"

Game::Game(AudioAdapter& audio, RenderAdapter& renderer) : audio(audio), renderer(renderer) {
	manager = new ObjectManager();
	factory = new ObjectFactory(*this);
}
Game::~Game() {
	delete factory;
	delete manager;
}

void Game::Destroy(GameObject* obj) const {
	manager->RemoveObject(obj);
}

template<class T> T* Game::Instantiate() const {
	T* t = factory->Instantiate<T>();
	manager->AddObject(t);
	return t;
}

void Game::Update() {
	manager->Update(audio);
}

void Game::Render() {
	manager->Render(renderer);
}

#include "Player.h"
#include "Bomb.h"
#include "GridMap.h"
#include "Wall.h"
#include "Destructable.h"

template Player* Game::Instantiate<Player>() const;
template Bomb* Game::Instantiate<Bomb>() const;
template GridMap* Game::Instantiate<GridMap>() const;
template Wall* Game::Instantiate<Wall>() const;
template Destructable* Game::Instantiate<Destructable>() const;