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
	Game(AudioAdapter& audio, RenderAdapter& renderer);
	virtual ~Game();

	virtual void initialize() = 0;

	template<class T> T* Instantiate() const;
	void Destroy(GameObject* obj) const;

	void Update();
	void Render();

private:
	ObjectFactory *factory;
	ObjectManager *manager;

protected:
	AudioAdapter& audio;
	RenderAdapter& renderer;
};

