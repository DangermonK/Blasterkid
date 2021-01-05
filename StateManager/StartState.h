#pragma once

#include "State.h"
#include <iostream>

class StartState : public State {

public:
	StartState(StateMaschine* sm) : State(sm) {}
	~StartState() {}

	virtual void Initialize() override {}

	virtual void Start() override {}

	virtual void Update() override {}

	virtual void Stop() override {}

};