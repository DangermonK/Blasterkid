#pragma once

#include "SceneManager.h"
#include <RenderAdapter.h>
#include <AudioAdapter.h>
#include <Event.h>

class SceneManager;

class Scene {

public:
	Scene(SceneManager& manager, AudioAdapter& audio, RenderAdapter& r);
	~Scene();

	virtual void Initialize() = 0;
	virtual void Quit() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void HandleInput(const Event& e) = 0;

protected:
	void SetScene(const std::string& name);
	void Stop();


	AudioAdapter& audio;
	RenderAdapter& renderer;
	
private:
	SceneManager& manager;

};