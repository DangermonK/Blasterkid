#pragma once

#include <map>
#include <string>
#include "Scene.h"
#include <RenderAdapter.h>
#include <AudioAdapter.h>
#include <Event.h>

class Scene;

class SceneManager {

public:
	SceneManager(RenderAdapter& renderer, AudioAdapter& audio);
	~SceneManager();

	template<class T = Scene>
	void AddScene(const std::string& name) {
		scene_vec.insert(std::pair<std::string, Scene*>(name, new T(*this, audio, renderer)));
	}

	void SetScene(const std::string& name);

	void Start();
	void Stop();

	bool IsRunning();

	void Update();
	void Render();
	void OnInput(const Event& input_event);

private:
	RenderAdapter& renderer;
	AudioAdapter& audio;

	std::map<std::string, Scene*> scene_vec;
	Scene* current_scene;

	bool running;
};
