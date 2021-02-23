#pragma once

#include "GridMapType.h"
#include "GameObject.h"

#include "Wall.h"
#include "Destructable.h"

#include <map>

class GridMap : public GameObject {

public:
	GridMap(const Game& mng, const unsigned int& u_id);
	GridMap(const Game& mng, const unsigned int& u_id, const unsigned int& rows, const unsigned int& cols);
	~GridMap();

	void Create(const unsigned int& rows, const unsigned int& cols);

	const GridMapType GetCell(const unsigned int& x, const unsigned int& y) const;

	void SetCell(const unsigned int& x, const unsigned int& y, const GridMapType& value) const;

	void SetWallTexture(const Texture& texture);
	void SetDestructableTexture(const Texture& texture);
	void SetGrasTexture(const Texture& texture);

	virtual void Update(const AudioAdapter& audio) override {};

	const unsigned int GetRows() const;
	const unsigned int GetCols() const;

private:
	GridMapType* map;
	std::map<std::pair<unsigned int, unsigned int>, Wall&> *obj_map;

	unsigned int rows;
	unsigned int cols;

	Texture wallTexture;
	Texture destructableTexture;
	Texture grasTexture;

	bool CheckCell(const unsigned int& x, const unsigned int& y) const;
};
