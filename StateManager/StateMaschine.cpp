#include "StateMaschine.h"
#include "StartState.h"

StateMaschine::StateMaschine() {
	AddState<StartState>(StateType::START_STATE);
	current_state = StateType::START_STATE;
	state_map[current_state]->Start();
}
StateMaschine::~StateMaschine() {}

void StateMaschine::SetState(StateType state) {
	if (state_map.count(state)) {
		state_map[current_state]->Stop();
		this->current_state = state;
		state_map[current_state]->Start();
	}
}

void StateMaschine::UpdateState() {
	state_map[current_state]->Update();
}

void StateMaschine::InitializeState(StateType state) {
	state_map[state]->Initialize();
}