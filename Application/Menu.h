#pragma once

#include "Scene.h"
#include <vector>

class GameMenu : public Scene {

public:
	GameMenu(SceneManager* manager, AudioAdapter& audio, RenderAdapter& renderer) : Scene(manager, audio, renderer) {
		index = 0;
	}
	~GameMenu() {}

	virtual void Start() override {
		menuitems.push_back("Spiel");
		menuitems.push_back("Editor");
		menuitems.push_back("Option");

		active = menuitems.begin();
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
				}
				break;
			case KeyCode::DOWN:
				if (active != menuitems.end() - 1) {
					active++;
					index++;
				}
				break;
			case KeyCode::RETURN:
				switch (index) {
				case 0: SetScene("Start"); break;
				case 1: break;
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
};