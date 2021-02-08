#pragma once

#include "GridObject.h"
#include "Timer.h"

class Player : public GridObject
{

public:
	Player(const ObjectManager& mng, const unsigned int& u_id);
	Player(const ObjectManager& mng, const unsigned int& u_id, const int& x, const int& y);
	~Player();

	void Update(const AudioAdapter& audio) override;

	void PressUp();
	void PressDown();
	void PressLeft();
	void PressRight();

	void ReleaseUp();
	void ReleaseDown();
	void ReleaseLeft();
	void ReleaseRight();

	void SetMap(GridMap* map);

private:
	float counter;
	bool l, r, u, d;

	GridMap* map;

	void UpdatePosition();

};

