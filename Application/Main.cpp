
#include "SceneManager.h"
#include "Scene.h"
#include "SFML_Audio.h"
#include "SFML_Display.h"
#include "SFML_Renderer.h"

#include <random>
#include <iostream>

#include "GridMap.h"
#include "Player.h"
#include "Bomb.h"

#include "Game.h"

#include "Timer.h"

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
				switch(index) {
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

class Test : public Scene {
	
public:
	Test(SceneManager* manager, AudioAdapter& audio) : Scene(manager, audio) {
		game = nullptr;
		player = nullptr;
		map = nullptr;
	}
	~Test() {}

	virtual void Start() override
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));		

		game = new Game();

		player = game->Instantiate<Player>();
		player->setPosition(10, 10);

		map = game->Instantiate<GridMap>();
		map->Create(25, 25);
		for (unsigned int i = 0; i < map->GetRows(); i++)
			for (unsigned int j = 0; j < map->GetCols(); j++)
				map->SetCell(j, i, (GridMapType)(rand() % (int)GridMapType::COUNT));
				
		player->SetMap(map);
	}

	virtual void Quit() override
	{
		delete game;
	}

	virtual void Update() override
	{
		game->Update(audio);
	}

	virtual void Render(const RenderAdapter& r) override
	{
		game->Render(r);

		r.DrawUIButton(0, 0, std::to_string(1 / Timer::getDeltaTime()));
	}

	virtual void HandleInput(const Event& e) override
	{
		switch (e.type)
		{
		case Event::KEY_DOWN: 
			switch (e.key)
			{
			case KeyCode::ESCAPE: SetScene("GameMenu"); break;
			case KeyCode::UP: player->PressUp(); break;
			case KeyCode::DOWN: player->PressDown(); break;
			case KeyCode::LEFT: player->PressLeft(); break;
			case KeyCode::RIGHT: player->PressRight(); break;
			default:
				break;
			} 
			break;

		case Event::KEY_UP:
			switch (e.key)
			{
			case KeyCode::UP: player->ReleaseUp(); break;
			case KeyCode::DOWN: player->ReleaseDown(); break;
			case KeyCode::LEFT: player->ReleaseLeft(); break;
			case KeyCode::RIGHT: player->ReleaseRight(); break;
			case KeyCode::LEFT_CTRL:  
			{
				Bomb* bomb = game->Instantiate<Bomb>();
				bomb->setPosition(Vector(std::roundf(player->getPosition().getX()), std::roundf(player->getPosition().getY())));
				bomb->SetMap(map);
			}	break;
			default: break;
			}
			break;
		default:
			break;
		}
	}

private:

	float counter = 0;
	Game* game;
	GridMap* map;
	Player* player;
};


int main() {

	SFMLDisplay display(500, 500, "test");
	SFMLRenderer* renderer = new SFMLRenderer(500, 500);
	SFMLAudio* audio = new SFMLAudio();
	SceneManager manager(renderer, *audio);
	manager.AddScene<GameMenu>("GameMenu");
	manager.AddScene<Test>("Start");
	
	manager.SetScene("GameMenu");
	bool run = true;
	while (run) {
		Timer::RefreshTimer();
		if (display.IsEvent()) {
			Event e = display.GetEvent();
			switch (e.type) {
			case Event::CLOSED: run = false;  display.Close(); break;
			default: manager.OnInput(e); break;
			}

		}
		manager.Update();
		manager.Render();
		display.Display(*renderer);
	}

	delete renderer;
	delete audio;

	return 0;
}