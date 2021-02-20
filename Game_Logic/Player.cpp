#include "Player.h"

Player::Player(const Game& mng, const unsigned int& u_id) : GridObject(mng, u_id) {
	map = nullptr;
	counter = 1;
	l = r = u = d = false;
}
Player::Player(const Game& mng, const unsigned int& u_id, const int& x, const int& y) : GridObject(mng, u_id, x, y) {
	map = nullptr;
	counter = 1;
	l = r = u = d = false;
}
Player::~Player() {
}

void Player::SetTexture(const Texture& texture) {
	this->txt = texture;
}

void Player::Render(const RenderAdapter& renderer) {
	renderer.Draw(txt, position.getX(), position.getY());
}

void Player::Update(const AudioAdapter& audio)
{
	if (l || r || u || d) {
		InterpolatePosition(counter);
		counter += Timer::getDeltaTime() *5;
		if (counter >= 1) {
			ResetToFirst();
			counter = 0;
			if (u) {
				MoveUp();
			}
			else if (d) {
				MoveDown();
			}
			else if (r) {
				MoveRight();
			}
			else if (l) {
				MoveLeft();
			}
			if (map->GetCell(getGridPositionX(), getGridPositionY()) != GridMapType::FLOOR) {
				if (map->GetCell(getGridPositionX(), getGridPositionY()) == GridMapType::DETSRUCTABLE) {
					map->SetCell(getGridPositionX(), getGridPositionY(), GridMapType::FLOOR);
					audio.Play("");
				}
				else {
					ResetToLast();
				}
			}
		}
	}
}

void Player::SetMap(GridMap* map) {
	this->map = map;
}

void Player::UpdatePosition() {

	if (u) {
		if (getLastGridPositionY() - getGridPositionY() < 0) {
			FlipPositionToLast();
			counter = 1.f - counter;
		}
	}
	else if (d) {
		if (getLastGridPositionY() - getGridPositionY() > 0) {
			FlipPositionToLast();
			counter = 1.f - counter;
		}
	}
	else if (r) {
		if (getLastGridPositionX() - getGridPositionX() > 0) {
			FlipPositionToLast();
			counter = 1.f - counter;
		}
	}
	else if (l) {
		if (getLastGridPositionX() - getGridPositionX() < 0) {
			FlipPositionToLast();
			counter = 1.f - counter;
		}
	}

}

void Player::PressUp() { u = true; UpdatePosition(); }
void Player::PressDown() { d = true; UpdatePosition(); }
void Player::PressLeft() { l = true; UpdatePosition(); }
void Player::PressRight() { r = true; UpdatePosition(); }

void Player::ReleaseUp() { u = false; }
void Player::ReleaseDown() { d = false; }
void Player::ReleaseLeft() { l = false; }
void Player::ReleaseRight() { r = false; }
