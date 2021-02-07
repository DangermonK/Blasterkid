#pragma once

#include "GameObject.h"
#include "GridMap.h"

class GridObject : public GameObject {

public:
	GridObject(const int& x, const int& y);
	GridObject();
	~GridObject();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	virtual void Update(const float& delta_time) = 0;

	void InterpolatePosition(const float& i);
	void FlipPositionToLast();
	void ResetToLast();

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