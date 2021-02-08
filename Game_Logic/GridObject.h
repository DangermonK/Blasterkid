#pragma once

#include "GameObject.h"
#include "GridMap.h"

class GridObject : public GameObject {

public:
	GridObject(const ObjectManager& mng, const unsigned int& u_id, const int& x, const int& y);
	GridObject(const ObjectManager& mng, const unsigned int& u_id);
	virtual ~GridObject();

	void setPosition(const Vector& position);
	void setPosition(const float& x, const float& y);

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	virtual void Update(const AudioAdapter& audio) = 0;

	void InterpolatePosition(const float& i);
	void FlipPositionToLast();
	void ResetToLast();
	void ResetToFirst();

	const int& getGridPositionX();
	const int& getGridPositionY();
	const int& getLastGridPositionX();
	const int& getLastGridPositionY();

private:
	int grid_x;
	int grid_y;
	int grid_lx;
	int grid_ly;

	void UpdateLastPosition();

};