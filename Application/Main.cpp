
#include "SceneManager.h"
#include "Scene.h"
#include "SFML_Audio.h"
#include "SFML_Display.h"
#include "SFML_Renderer.h"

#include <ctime>
#include <random>
#include <iostream>

#include "GridMap.h"
#include "Player.h"

class Test : public Scene {
	
public:
	Test(SceneManager* manager, AudioAdapter& audio) : Scene(manager, audio) {
		map = new GridMap(20, 20);
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				map->SetCell(j, i, (GridMapType)(rand() % (int)GridMapType::COUNT));

		player = new Player(10, 10);

	}
	~Test() {}

	virtual void Start() override
	{
		now = (float)std::clock();
	}

	virtual void Quit() override
	{
	}

	virtual void Update() override
	{
		last = now;
		now = (float)std::clock();
		delta = (now - last) / CLOCKS_PER_SEC;
		if (map->GetCell(player->getGridPositionX(), player->getGridPositionY()) != GridMapType::FLOOR) {
			if (map->GetCell(player->getGridPositionX(), player->getGridPositionY()) == GridMapType::DETSRUCTABLE) {
				map->SetCell(player->getGridPositionX(), player->getGridPositionY(), GridMapType::FLOOR);
				audio.Play("");
			}
			else {
				player->ResetToLast();
			}
		}
		player->Update(delta);
	}

	int size = 40;

	virtual void Render(const RenderAdapter& r) override
	{
		for (unsigned int i = 0; i < map->GetRows(); i++)
			for (unsigned int j = 0; j < map->GetRows(); j++) {
				if (map->GetCell(j, i) == GridMapType::FLOOR)
					r.DrawGreenBox((float)(j * size), (float)(i * size), (float)(size), (float)(size));
				else if (map->GetCell(j, i) == GridMapType::DETSRUCTABLE)
					r.DrawRedBox((float)(j * size), (float)(i * size), (float)(size), (float)(size));
			}

		r.DrawBlueBox(player->getPosition().getX() * size + 10, player->getPosition().getY() * size + 10, (float)(size - 20), (float)(size - 20));
	
	}

	virtual void HandleInput(const Event& e) override
	{
		switch (e.type)
		{
		case Event::KEY_DOWN: 
			switch (e.key)
			{
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
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

private:
	float now;
	float last;
	float delta;

	float counter = 0;
	GridMap *map;

	Player* player;
};

int main() {

	SFMLDisplay display(800, 800, "test");
	SFMLRenderer* renderer = new SFMLRenderer(800, 800);
	SFMLAudio* audio = new SFMLAudio();
	SceneManager manager(renderer, *audio);
	manager.AddScene<Test>("Start");
	manager.SetScene("Start");
	bool run = true;
	while (run) {
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