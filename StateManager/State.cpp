#include "State.h"

State::State(StateMaschine* sm) {
	this->sm = sm;
}

State::~State() {}

void State::SetState(StateType state) {
	sm->SetState(state);
}