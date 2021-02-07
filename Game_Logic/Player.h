#pragma once

#include "GridObject.h"

class Player : public GridObject
{

public:
	Player();
	Player(const int& x, const int& y);
	~Player();

	virtual void Update(const float& delta_time) override;

	void PressUp();
	void PressDown();
	void PressLeft();
	void PressRight();

	void ReleaseUp();
	void ReleaseDown();
	void ReleaseLeft();
	void ReleaseRight();

private:
	float counter;
	bool l, r, u, d;

	void UpdatePosition();

};

