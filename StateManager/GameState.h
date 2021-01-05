#pragma once

#include "State.h"
#include <iostream>

#include "Game.h"

class GameState : public State {

private:
	Game game;

public:
	GameState(StateMaschine* sm) : State(sm) {}
	~GameState() {}

	virtual void Initialize() override {}

	virtual void Start() override {}

	virtual void Update() override {}

	virtual void Stop() override {}

};