#pragma once
#include "GridObject.h"

#include "GridMap.h"

class Bomb : public GridObject
{

public:
	Bomb(const ObjectManager& mng, const unsigned int& u_id);
	~Bomb();

	void SetMap(GridMap* map);

	void Update(const AudioAdapter& audio) override;
	void Render(const RenderAdapter& audio) override;

private:
	float counter;

	GridMap* map;

};

