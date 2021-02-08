#pragma once

#include "ObjectFactory.h"
#include "ObjectManager.h"

#include "GameObject.h"

class GameObject;
class ObjectManager;
class ObjectFactory;

class Game
{
public:
	Game();
	virtual ~Game();

	template<class T> T* Instantiate() const;
	void Destroy(GameObject* obj) const;

	void Update(const AudioAdapter& audio);
	void Render(const RenderAdapter& renderer);

private:
	ObjectFactory *factory;
	ObjectManager *manager;

};

