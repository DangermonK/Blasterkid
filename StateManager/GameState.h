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
		Instantiate(TYPE::TEST, Vector(9, 15));
		Game::Initialize();
	}

	virtual void Start() override {}

	virtual void Update() override {
	}

	virtual void Render(DisplayAdapter* adapter) override {
		auto ph = manager->GetObjectsOfType<PhysicsObject>();
	
		for (auto it = ph.begin(); it != ph.end(); it++) {
			PhysicsObject* obj = *it;
			adapter->DrawRect(obj->GetBounds().GetPosition().x, obj->GetBounds().GetPosition().y, obj->GetBounds().GetSize().x, obj->GetBounds().GetSize().y);
		}
	}

	virtual void Stop() override {}

};