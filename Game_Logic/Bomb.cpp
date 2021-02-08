#include "Bomb.h"

Bomb::Bomb(const ObjectManager& mng, const unsigned int& u_id) : GridObject(mng, u_id) {
	map = nullptr;
	counter = 0;
}
Bomb::~Bomb() {

}

void Bomb::Render(const RenderAdapter& renderer) {
	renderer.DrawMagentaBox(position.getX(), position.getY());
}


void Bomb::SetMap(GridMap* map) {
	this->map = map;
}

void Bomb::Update(const AudioAdapter& audio) {
	counter += Timer::getDeltaTime();
	if (counter > 3) {
		mng.RemoveObject(this);
		map->SetCell(getGridPositionX() - 1, getGridPositionY(), GridMapType::FLOOR);
		map->SetCell(getGridPositionX() + 1, getGridPositionY(), GridMapType::FLOOR);
		map->SetCell(getGridPositionX(), getGridPositionY() - 1, GridMapType::FLOOR);
		map->SetCell(getGridPositionX(), getGridPositionY() + 1, GridMapType::FLOOR);
		audio.Play("");
	}
}