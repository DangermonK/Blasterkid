#pragma once

#include "State.h"
#include <iostream>

#include "../Blasterkid/Game.h"
#include "../Blasterkid/PhysicsObject.h"

class GameState : public State, Game {

public:
	GameState(StateMaschine* sm) : State(sm) {}
	~GameState() {}

	virtual void Initialize() override {
		
		Instantiate(TYPE::TEST, Vector(10, 10));
		Instantiate(TYPE::TEST, Vector(10, 10));
		
		
		Game::Initialize();
	}

	virtual void Start() override {}

	virtual void Update() override {
		Game::Update();
	}

	virtual void Render(DisplayAdapter* adapter) override {
		auto ph = manager->GetPhxLList();
	
		for (auto it = ph.begin(); it != ph.end(); it++) {
			adapter->DrawRect((*it)->GetBounds().GetPosition().x, (*it)->GetBounds().GetPosition().y, 
				(*it)->GetBounds().GetSize().x, (*it)->GetBounds().GetSize().y);
		}
	}

	virtual void Stop() override {}

};