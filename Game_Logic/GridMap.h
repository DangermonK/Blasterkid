#pragma once

#include "GridMapType.h"

class GridMap {

public:
	GridMap(const int& rows, const int& cols);
	~GridMap();

	const GridMapType& GetCell(const int& x, const int& y) const;

	void SetCell(const int& x, const int& y, const GridMapType& value) const;

	const unsigned int& GetRows() const;
	const unsigned int& GetCols() const;

private:
	GridMapType* map;
	const int rows;
	const int cols;

	bool CheckCell(const int& x, const int& y) const;

};
