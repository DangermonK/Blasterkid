#include "SinglePlayerGame.h"

SinglePlayerGame::SinglePlayerGame(AudioAdapter& audio, RenderAdapter& renderer) : Game(audio, renderer) {}
SinglePlayerGame::~SinglePlayerGame() {}


void SinglePlayerGame::initialize()
{

	player = Instantiate<Player>();
	player->setPosition(10, 10);
	player->SetTexture(renderer.LoadFromFile("Player_Idle.png"));
	player->setZIndex(1);
	map = Instantiate<GridMap>();
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
