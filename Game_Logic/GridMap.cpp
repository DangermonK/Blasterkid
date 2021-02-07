#include "GridMap.h"

GridMap::GridMap(const int& rows, const int& cols) : rows(rows), cols(cols) {
	const int size = rows * cols;
	map = new GridMapType[size];
}

GridMap::~GridMap() {}

const GridMapType& GridMap::GetCell(const int& x, const int& y) const {
	return (CheckCell(x, y) ? map[y * rows + x] : GridMapType::WALL);
}

void GridMap::SetCell(const int& x, const int& y, const GridMapType& value) const {
	if (CheckCell(x, y)) {
		map[y * rows + x] = value;
	}
}

const unsigned int& GridMap::GetRows() const { return rows; }
const unsigned int& GridMap::GetCols() const { return cols; }

bool GridMap::CheckCell(const int& x, const int& y) const {
	return x >= 0 && x < cols&& y >= 0 && y < rows;
}