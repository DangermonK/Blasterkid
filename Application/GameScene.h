#pragma once

#include "Scene.h"
#include "SinglePlayerGame.h"

#include "GridMap.h"
#include "Player.h"

class Test : public Scene {

public:
	Test(SceneManager& manager, AudioAdapter& audio, RenderAdapter& renderer) : Scene(manager, audio, renderer) {
		game = nullptr;
		player = nullptr;
		map = nullptr;
	}
	~Test() {}

	virtual void Initialize() override
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		
		Music m = audio.LoadMusicFromFile("Track1.wav");
		audio.Play(m);
	
		game = new SinglePlayerGame(audio, renderer);
		
		player = game->Instantiate<Player>();
		player->setPosition(10, 10);
		player->SetTexture(renderer.LoadFromFile("Player_Idle.png"));
		player->setZIndex(1);
		map = game->Instantiate<GridMap>();
		map->Create(15, 15);
		map->SetTexture(renderer.LoadFromFile("Empty.png"));
		map->SetWallTexture(renderer.LoadFromFile("Wall.png"));
		map->SetGrasTexture(renderer.LoadFromFile("Gras.png"));
		map->SetDestructableTexture(renderer.LoadFromFile("Destructable.png"));
		for (unsigned int i = 0; i < map->GetRows(); i++)
			for (unsigned int j = 0; j < map->GetCols(); j++)
				map->SetCell(j, i, (GridMapType)(rand() % (int)GridMapType::COUNT));

		bomb_tex = renderer.LoadFromFile("Bomb.png");
		player->SetMap(map);
	}

	virtual void Quit() override
	{
		delete game;
	}

	virtual void Update() override
	{
		game->Update();
	}

	virtual void Render() override
	{
		game->Render();
		
		renderer.DrawUIButton(0, 0, std::to_string((int)(1 / Timer::getDeltaTime())) + " FPS");
	}

	virtual void HandleInput(const Event& e) override
	{
		switch (e.type)
		{
		case Event::KEY_DOWN:
			switch (e.key)
			{
			case KeyCode::ESCAPE: SetScene("Pause"); break;
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
				bomb->setZIndex(1);
				bomb->SetTexture(bomb_tex);
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
	Texture bomb_tex;
	Game* game;
	GridMap* map;
	Player* player;
};