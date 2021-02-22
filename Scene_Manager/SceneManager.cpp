#include "SceneManager.h"

SceneManager::SceneManager(RenderAdapter& renderer, AudioAdapter& audio) : audio(audio), renderer(renderer) {
	running = false;
	current_scene = nullptr;
}
SceneManager::~SceneManager() {}

void SceneManager::Start() {
	running = true;
}
void SceneManager::Stop() {
	running = false;
}

bool SceneManager::IsRunning() {
	return std::move(running);
}

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
		if (current_scene != nullptr) {
			current_scene->Quit();
		}
		
		renderer.ClearCache();

		current_scene = scene_vec[name];
		current_scene->Initialize();
	}
}
