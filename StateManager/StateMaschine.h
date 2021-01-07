#pragma once

class State;

#include <map>
#include "StateType.h"
#include "State.h"

#include "../IOAdapter/DisplayAdapter.h"

class StateMaschine
{
private:
	std::map<StateType, State*> state_map;
	StateType current_state;

	DisplayAdapter* display_adapter;

	void InitializeState(StateType state);

public:
	StateMaschine(DisplayAdapter* adapter);
	~StateMaschine();

	template<class T = State>
	void AddState(StateType state) {
		state_map.insert(std::pair<StateType, State*>(state, new T(this)));
		InitializeState(state);
	}

	void SetState(StateType state);
	void UpdateState();
	void RenderState();

};

