#include "SceneManager.h"

SceneManager::SceneManager(RenderAdapter& renderer, AudioAdapter& audio) : audio(audio), renderer(renderer) {
	current_scene = nullptr;
}
SceneManager::~SceneManager() {}

void SceneManager::Update() {
	current_scene->Update();
}

void SceneManager::Render() {
	renderer.Clear();
	current_scene->Render();
	renderer.Render();
}

void SceneManager::OnInput(const Event& input_event) {
	current_scene->HandleInput(input_event);
}

void SceneManager::SetScene(const std::string& name) {
	if (scene_vec.count(name)) {
		if (current_scene != nullptr)
			current_scene->Quit();

		current_scene = scene_vec[name];
		current_scene->Start();
	}
}