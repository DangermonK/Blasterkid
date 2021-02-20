#pragma once

#include "Scene.h"
#include "Game.h"

#include "GridMap.h"
#include "Player.h"

class Test : public Scene {

public:
	Test(SceneManager* manager, AudioAdapter& audio, RenderAdapter& renderer) : Scene(manager, audio, renderer) {
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
		player->SetTexture(renderer.LoadFromFile("fries.png"));
		player->setPosition(10, 10);

		map = game->Instantiate<GridMap>();
		map->Create(15, 15);
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

	virtual void Render() override
	{
		game->Render(renderer);

		renderer.DrawUIButton(0, 0, std::to_string((int)(1 / Timer::getDeltaTime())) + " FPS");
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