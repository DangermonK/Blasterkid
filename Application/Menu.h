#pragma once

#include "Scene.h"
#include <vector>

class GameMenu : public Scene {

public:
	GameMenu(SceneManager& manager, AudioAdapter& audio, RenderAdapter& renderer) : Scene(manager, audio, renderer) {
		index = 0;
	}
	~GameMenu() {}

	virtual void Initialize() override
	{
		index = 0;
		menuitems.push_back("Spiel");
		menuitems.push_back("Credits");
		menuitems.push_back("Beenden");

		bomb = renderer.LoadFromFile("bomb_render.png");
		menu_click = audio.LoadFromFile("menu_click.wav");

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

		renderer.Draw(bomb, 200, 200);

		int pos = 0;
		for (auto it = menuitems.begin(); it != menuitems.end(); it++) {

			if (it == active) {
				renderer.DrawUIButtonRed(110, 100 + (float)pos * 20, *it);
			}
			else {
				renderer.DrawUIButton(100, 100 + (float)pos * 20, *it);
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
				case 0: SetScene("Start"); break;
				case 2: Stop(); break;
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

	Texture bomb;
	Sound menu_click;
};