#include "Scene.h"

Scene::Scene(SceneManager* manager, AudioAdapter& audio) : audio(audio) {
	this->manager = manager;
}

Scene::~Scene() {}

void Scene::SetScene(const std::string& name) {
	manager->SetScene(name);
}