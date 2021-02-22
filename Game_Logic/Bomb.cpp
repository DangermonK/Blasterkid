#include "Bomb.h"

Bomb::Bomb(const Game& mng, const unsigned int& u_id) : GridObject(mng, u_id) {
	map = nullptr;
	counter = 0;
}
Bomb::~Bomb() {

}

void Bomb::SetMap(GridMap* map) {
	this->map = map;
}

void Bomb::Update(const AudioAdapter& audio) {
	counter += Timer::getDeltaTime();
	if (counter > 3) {
		game.Destroy(this);
		if(map->GetCell(getGridPositionX() - 1, getGridPositionY()) == GridMapType::DETSRUCTABLE)
			map->SetCell(getGridPositionX() - 1, getGridPositionY(), GridMapType::FLOOR);
		if (map->GetCell(getGridPositionX() + 1, getGridPositionY()) == GridMapType::DETSRUCTABLE)
			map->SetCell(getGridPositionX() + 1, getGridPositionY(), GridMapType::FLOOR);
		if (map->GetCell(getGridPositionX(), getGridPositionY() - 1) == GridMapType::DETSRUCTABLE)
			map->SetCell(getGridPositionX(), getGridPositionY() - 1, GridMapType::FLOOR);
		if (map->GetCell(getGridPositionX(), getGridPositionY() + 1) == GridMapType::DETSRUCTABLE)
			map->SetCell(getGridPositionX(), getGridPositionY() + 1, GridMapType::FLOOR);
		audio.Play("");
	}
}