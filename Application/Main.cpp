
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

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Timer.h"

#define CELL_SIZE 10

class Test : public Scene {
	
public:
	Test(SceneManager* manager, AudioAdapter& audio) : Scene(manager, audio) {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		mng = ObjectManager();
		fac = new ObjectFactory(mng);
		
		player = fac->Instantiate<Player>();
		player->setPosition(10, 10);
		
		map = fac->Instantiate<GridMap>();
		map->Create(50, 50);
		for (int i = 0; i < map->GetRows(); i++)
			for (int j = 0; j < map->GetCols(); j++)
				map->SetCell(j, i, (GridMapType)(rand() % (int)GridMapType::COUNT));

		
		player->SetMap(map);
	}
	~Test() {}

	virtual void Start() override
	{
	}

	virtual void Quit() override
	{
	}

	virtual void Update() override
	{
		mng.Update(audio);
	}

	int size = 40;

	virtual void Render(const RenderAdapter& r) override
	{
		mng.Render(r);
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
			case KeyCode::LEFT_CTRL:  
			{
				Bomb* bomb = fac->Instantiate<Bomb>();
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
	GridMap* map;
	ObjectManager mng;
	ObjectFactory *fac;

	Player* player;
};


int main() {

	SFMLDisplay display(500, 500, "test");
	SFMLRenderer* renderer = new SFMLRenderer(500, 500);
	SFMLAudio* audio = new SFMLAudio();
	SceneManager manager(renderer, *audio);
	manager.AddScene<Test>("Start");
	manager.SetScene("Start");
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