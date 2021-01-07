#pragma once

class StateMaschine;

#include "StateMaschine.h"
#include "../IOAdapter/DisplayAdapter.h"

class State
{

private:
	StateMaschine* sm;

public:
	State(StateMaschine* sm);
	~State();

	void SetState(StateType state);

	virtual void Initialize() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render(DisplayAdapter* adapter) = 0;
	virtual void Stop() = 0;

};

