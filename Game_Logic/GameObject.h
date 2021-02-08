#pragma once

#include "Vector.h"
#include "ObjectManager.h"

#include "Timer.h"

#include "RenderAdapter.h"
#include "AudioAdapter.h"

class ObjectManager;

class GameObject
{

public:
	GameObject(const ObjectManager& mng, const unsigned int& u_id);
	GameObject(const ObjectManager& mng, const unsigned int& u_id, const float& x, const float& y);
	GameObject(const ObjectManager& mng, const unsigned int& u_id, const Vector& position);
	virtual ~GameObject();

	friend bool operator==(const GameObject& lhs, const GameObject& rhs) { return lhs.U_ID == rhs.U_ID; };

	virtual void Update(const AudioAdapter& audio) = 0;
	virtual void Render(const RenderAdapter& renderer);

	Vector getPosition();
	void setPosition(const float& x, const float& y);
	void setPosition(const Vector& position);

protected:
	Vector position;

	const ObjectManager& mng;

private:
	const unsigned int U_ID;

};

