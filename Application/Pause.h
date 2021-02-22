#pragma once

#include "Scene.h"
#include <vector>

class Pause : public Scene {

public:
	Pause(SceneManager& manager, AudioAdapter& audio, RenderAdapter& renderer) : Scene(manager, audio, renderer) {
		
	}
	~Pause() {}

	virtual void Initialize() override
	{
		index = 0;
		menuitems.push_back("Fortsetzen");
		menuitems.push_back("Beenden");

		active = menuitems.begin();
		menu_click = audio.LoadFromFile("menu_click.wav");

	}

	virtual void Quit() override
	{
		menuitems.clear();
	}

	virtual void Update() override
	{
	}

	virtual void Render() override
	{
		int pos = 0;
		for (auto it = menuitems.begin(); it != menuitems.end(); it++) {

			if (it == active) {
				renderer.DrawUIButtonRed(110, 100 + pos * 20, *it);
			}
			else {
				renderer.DrawUIButton(100, 100 + pos * 20, *it);
			}
			pos++;
		}
	}

	virtual void HandleInput(const Event& e) override
	{
		switch (e.type)
		{
		case Event::KEY_DOWN:
			switch (e.key)
			{
			case KeyCode::UP:
				if (active != menuitems.begin()) {
					active--;
					index--;
					audio.Play(menu_click);
				}
				break;
			case KeyCode::DOWN:
				if (active != menuitems.end() - 1) {
					active++;
					index++;
					audio.Play(menu_click);
				}
				break;
			case KeyCode::RETURN:
				switch (index) {
				case 0: 
					SetScene("Start"); 
					break;
				case 1: 
					SetScene("GameMenu"); 
					break;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

private:
	std::vector<std::string> menuitems;
	std::vector<std::string>::iterator active;
	int index;
	Sound menu_click;
};