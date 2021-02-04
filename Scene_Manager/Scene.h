#pragma once

#include "SceneManager.h"
#include <RenderAdapter.h>
#include <AudioAdapter.h>
#include <Event.h>

class SceneManager;

class Scene {

public:
	Scene(SceneManager* manager, AudioAdapter& audio);
	~Scene();

	virtual void Start() = 0;
	virtual void Quit() = 0;
	virtual void Update() = 0;
	virtual void Render(const RenderAdapter& r) = 0;
	virtual void HandleInput(const Event& e) = 0;

	void SetScene(const std::string& name);

protected:
	AudioAdapter& audio;

private:
	SceneManager* manager;

};