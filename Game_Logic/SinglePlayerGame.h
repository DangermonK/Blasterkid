#pragma once
#include "Game.h"
#include "GridMap.h"
#include "Player.h"

class SinglePlayerGame : public Game
{
public:
	SinglePlayerGame(AudioAdapter& audio, RenderAdapter& renderer);
	~SinglePlayerGame();

	virtual void initialize() override;

private:
	GridMap* map;
	Player* player;

	Texture bomb_tex;
};

