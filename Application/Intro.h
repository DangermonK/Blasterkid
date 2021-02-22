#pragma once

#include "Scene.h"

class Intro : public Scene {
	
public:
	Intro(SceneManager& manager, AudioAdapter& audio, RenderAdapter& renderer) : Scene(manager, audio, renderer) {}
	~Intro() {}

	virtual void Initialize() override
	{
		logo = renderer.LoadFromFile("Dangermonk_Logo.png");
		counter = 5;
		scale = 0.0f;
		x = renderer.GetWidth();
	}

	virtual void Quit() override {}
	virtual void Update() override {
		scale += Timer::getDeltaTime()*0.2f;
		x -= Timer::getDeltaTime() * 200.f;
		if (x < renderer.GetWidth() * 0.1f)
			SetScene("GameMenu");

	}
	virtual void Render() override {
		renderer.Draw(logo, x,
							renderer.GetHeight() * 0.5f - logo.getHeight() * 0.5f * scale, scale);
	}
	virtual void HandleInput(const Event& e) override {}

private:
	Texture logo;

	float x;
	float counter;
	float scale;

};