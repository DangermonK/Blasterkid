#pragma once

#include "State.h"
#include <iostream>

#include "../Blasterkid/Game.h"

class GameState : public State {

private:
	Game game;

public:
	GameState(StateMaschine* sm) : State(sm) {}
	~GameState() {}

	virtual void Initialize() override {
		game.Instantiate(TYPE::TEST, Vector(10, 10));
		game.Instantiate(TYPE::TEST, Vector(10, 10));
		game.Initialize();
	}

	virtual void Start() override {}

	virtual void Update() override {
		game.Update();
	}

	virtual void Stop() override {}

};