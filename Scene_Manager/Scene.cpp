#include "Scene.h"

Scene::Scene(SceneManager* manager, AudioAdapter& audio, RenderAdapter& renderer) : audio(audio), renderer(renderer) {
	this->manager = manager;
}

Scene::~Scene() {}

void Scene::SetScene(const std::string& name) {
	manager->SetScene(name);
}