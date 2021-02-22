#include "Destructable.h"

Destructable::Destructable(const Game& game, const unsigned int& u_id) : Wall(game, u_id) {}
Destructable::~Destructable() {}

void Destructable::Destroy() {
	game.Destroy(this);
}