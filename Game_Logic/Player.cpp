#include "Player.h"

Player::Player() : GridObject() {
	counter = 10;
	l = r = u = d = false;
}
Player::Player(const int& x, const int& y) : GridObject(x, y) {
	counter = 10;
	l = r = u = d = false;
}
Player::~Player() {}

void Player::Update(const float& delta_time)
{
	if (l || r || u || d) {
		InterpolatePosition(counter);
		counter += delta_time * 5;
		if (counter >= 1) {
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
			counter = 0;
		}

	}
}

void Player::UpdatePosition() {

	if (u) {
		if (getLastGridPositionY() - getGridPositionY() < 0) {
			FlipPositionToLast();
			counter = 1 - counter;
		};
	}
	else if (d) {
		if (getLastGridPositionY() - getGridPositionY() > 0) {
			FlipPositionToLast();
			counter = 1 - counter;
		};
	}
	else if (r) {
		if (getLastGridPositionX() - getGridPositionX() > 0) {
			FlipPositionToLast();
			counter = 1 - counter;
		};
	}
	else if (l) {
		if (getLastGridPositionX() - getGridPositionX() < 0) {
			FlipPositionToLast();
			counter = 1 - counter;
		};
	}
	else {
		counter = 1;
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
