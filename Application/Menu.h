#pragma once

#include "Scene.h"
#include <vector>

class GameMenu : public Scene {

public:
	GameMenu(SceneManager* manager, AudioAdapter& audio) : Scene(manager, audio) {

	}
	~GameMenu() {}

	virtual void Start() override {
		menuitems.push_back("Spiel");
		menuitems.push_back("Editor");
		menuitems.push_back("Option");
		menuitems.push_back("Exit");

		active = menuitems.begin();
		index = 0;
	}

	virtual void Quit() override
	{
		menuitems.clear();
	}

	virtual void Update() override
	{
	}

	virtual void Render(const RenderAdapter& r) override
	{
		int pos = 0;
		for (auto it = menuitems.begin(); it != menuitems.end(); it++) {

			if (it == active) {
				r.DrawUIButtonRed(110, 100 + pos * 20, *it);
			}
			else {
				r.DrawUIButton(100, 100 + pos * 20, *it);
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