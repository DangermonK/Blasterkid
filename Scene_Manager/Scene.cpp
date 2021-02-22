#include "Scene.h"

Scene::Scene(SceneManager& manager, AudioAdapter& audio, RenderAdapter& renderer) : manager(manager), audio(audio), renderer(renderer) {
}

Scene::~Scene() {}

void Scene::SetScene(const std::string& name) {
	manager.SetScene(name);
}

void Scene::Stop() {
	manager.Stop();
}
