#include "GridMap.h"

GridMap::GridMap(const ObjectManager& mng, const unsigned int& u_id) : GameObject(mng, u_id) {
	cols = rows = 0;
	map = nullptr;
}
GridMap::GridMap(const ObjectManager& mng, const unsigned int& u_id, const int& rows, const int& cols) : GameObject(mng, u_id) {
	this->cols = cols;
	this->rows = rows;
	const int size = rows * cols;
	map = new GridMapType[size];
}

GridMap::~GridMap() {}

void GridMap::Render(const RenderAdapter& renderer) {
	for (unsigned int i = 0; i < rows; i++)
		for (unsigned int j = 0; j < cols; j++) {
			if (GetCell(j, i) == GridMapType::FLOOR)
				renderer.DrawGreenBox(j, i);
			else if (GetCell(j, i) == GridMapType::DETSRUCTABLE)
				renderer.DrawRedBox(j, i);
		}
}

void GridMap::Create(const int& rows, const int& cols) {
	this->rows = rows;
	this->cols = cols;
	const int size = rows * cols;
	map = new GridMapType[size];
}

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