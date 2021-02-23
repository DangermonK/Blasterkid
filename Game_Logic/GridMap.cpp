#include "GridMap.h"

GridMap::GridMap(const Game& mng, const unsigned int& u_id) : GameObject(mng, u_id) {
	cols = rows = 0;
	map = nullptr;
	obj_map = nullptr;
}
GridMap::GridMap(const Game& mng, const unsigned int& u_id, const unsigned int& rows, const unsigned int& cols) : GameObject(mng, u_id) {
	Create(rows, cols);
	obj_map = nullptr;
}

GridMap::~GridMap() {
	delete map;
	obj_map->clear();
	delete obj_map;
}

void GridMap::Create(const unsigned int& rows, const unsigned int& cols) {
	this->rows = rows;
	this->cols = cols;
	const int size = rows * cols;
	map = new GridMapType[size];
	obj_map = new std::map<std::pair<unsigned int, unsigned int>, Wall&>();
}

const GridMapType GridMap::GetCell(const unsigned int& x, const unsigned int& y) const {
	return (CheckCell(x, y) ? map[y * rows + x] : GridMapType::WALL);
}

void GridMap::SetCell(const unsigned int& x, const unsigned int& y, const GridMapType& value) const {
	if (CheckCell(x, y)) {
		if (value == GridMapType::WALL) {
			Wall& w = *game.Instantiate<Wall>();
			w.setZIndex(1);
			w.setPosition((float)x, (float)y);
			w.SetTexture(wallTexture);
			obj_map->insert(std::pair<std::pair<unsigned int, unsigned int>, Wall&>(std::pair<unsigned int, unsigned int>(x, y), w));
		}
		else if (value == GridMapType::DETSRUCTABLE) {
			Destructable& d = *game.Instantiate<Destructable>();
			d.setZIndex(1);

			d.setPosition((float)x, (float)y);
			d.SetTexture(destructableTexture);
			obj_map->insert(std::pair<std::pair<unsigned int, unsigned int>, Wall&>(std::pair<unsigned int, unsigned int>(x, y), d));
		}
		else {
			if (obj_map->count(std::pair<unsigned int, unsigned int>(x, y)) && map[y * rows + x] == GridMapType::DETSRUCTABLE) {
				Destructable& d = reinterpret_cast<Destructable&>(obj_map->at(std::pair<unsigned int, unsigned int>(x, y)));
				d.setZIndex(0);
				d.SetTexture(grasTexture);
			}
			else {
				Wall& w = *game.Instantiate<Wall>();
				w.setZIndex(0);
				w.setPosition((float)x, (float)y);
				w.SetTexture(grasTexture);
				obj_map->insert(std::pair<std::pair<unsigned int, unsigned int>, Wall&>(std::pair<unsigned int, unsigned int>(x, y), w));
			}
		}
		map[y * rows + x] = value;
	}
}

void GridMap::SetWallTexture(const Texture& texture) {
	this->wallTexture = texture;
}
void GridMap::SetDestructableTexture(const Texture& texture) {
	this->destructableTexture = texture;
}
void GridMap::SetGrasTexture(const Texture& texture) {
	this->grasTexture = texture;
}

const unsigned int GridMap::GetRows() const { return rows; }
const unsigned int GridMap::GetCols() const { return cols; }

bool GridMap::CheckCell(const unsigned int& x, const unsigned int& y) const {
	return x >= 0 && x < cols&& y >= 0 && y < rows;
}