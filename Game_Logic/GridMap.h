#pragma once

#include "GridMapType.h"
#include "GameObject.h"

class GridMap : public GameObject {

public:
	GridMap(const Game& mng, const unsigned int& u_id);
	GridMap(const Game& mng, const unsigned int& u_id, const unsigned int& rows, const unsigned int& cols);
	~GridMap();

	void Create(const unsigned int& rows, const unsigned int& cols);

	const GridMapType GetCell(const unsigned int& x, const unsigned int& y) const;

	void SetCell(const unsigned int& x, const unsigned int& y, const GridMapType& value) const;

	virtual void Update(const AudioAdapter& audio) override {};
	virtual void Render(const RenderAdapter& renderer) override;

	const unsigned int GetRows() const;
	const unsigned int GetCols() const;

private:
	GridMapType* map;
	unsigned int rows;
	unsigned int cols;

	bool CheckCell(const unsigned int& x, const unsigned int& y) const;
	Texture* tx;
};
