#pragma once

#include "GridMapType.h"
#include "GameObject.h"

class GridMap : public GameObject {

public:
	GridMap(const ObjectManager& mng, const unsigned int& u_id);
	GridMap(const ObjectManager& mng, const unsigned int& u_id, const int& rows, const int& cols);
	~GridMap();

	void Create(const int& rows, const int& cols);

	const GridMapType& GetCell(const int& x, const int& y) const;

	void SetCell(const int& x, const int& y, const GridMapType& value) const;

	virtual void Update(const AudioAdapter& audio) override {};
	virtual void Render(const RenderAdapter& renderer) override;

	const unsigned int& GetRows() const;
	const unsigned int& GetCols() const;

private:
	GridMapType* map;
	int rows;
	int cols;

	bool CheckCell(const int& x, const int& y) const;

};
