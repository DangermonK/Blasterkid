#include "StateMaschine.h"
#include "StartState.h"

StateMaschine::StateMaschine(DisplayAdapter* adapter) {
	AddState<StartState>(StateType::START_STATE);
	current_state = StateType::START_STATE;
	state_map[current_state]->Start();

	this->display_adapter = adapter;

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

void StateMaschine::RenderState() {
	display_adapter->ClearDisplay();
	state_map[current_state]->Render(display_adapter);
	display_adapter->Display();
}

void StateMaschine::InitializeState(StateType state) {
	state_map[state]->Initialize();
}