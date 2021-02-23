#pragma once

#include "Scene.h"

class Intro : public Scene {
	
public:
	Intro(SceneManager& manager, AudioAdapter& audio, RenderAdapter& renderer) : Scene(manager, audio, renderer) {}
	~Intro() {}

	virtual void Initialize() override
	{
		logo = renderer.LoadFromFile("Dangermonk_Logo.png");
		intro = audio.LoadFromFile("intro.wav");
		timer = 6;
		alpha = 0;
		scale = .7f;
		played = false;
	}

	virtual void Quit() override {}
	virtual void Update() override {
		timer -= Timer::getDeltaTime();
		if (timer <= 5) {
			if (!played) {
				audio.Play(intro);
				played = true;
			}
			if (timer <= 4) {
				if (timer > 1.5f) {
					alpha += Timer::getDeltaTime();
					if (alpha >= 1)
						alpha = 1;
				}
				else {
					alpha -= Timer::getDeltaTime();
					if (alpha <= 0)
						alpha = 0;
				}

				if (timer <= 0)
					SetScene("GameMenu");
			}
		}

	}
	virtual void Render() override {
		renderer.Draw(logo, renderer.GetWidth() * 0.5f - logo.getWidth() * 0.5f * scale,
							renderer.GetHeight() * 0.5f - logo.getHeight() * 0.5f * scale, scale, alpha);
	}
	virtual void HandleInput(const Event& e) override {}

private:
	Texture logo;
	Sound intro;

	bool played;
	float alpha;
	float scale;
	float timer;

};