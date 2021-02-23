#pragma once

#include "GameObject.h"
#include <list>
#include <stack>

#include "RenderAdapter.h"
#include "AudioAdapter.h"

class GameObject;

class ObjectManager
{

public:
	ObjectManager();
	~ObjectManager();

	void AddObject(GameObject* obj);
	void RemoveObject(GameObject* obj);

	void Update(const AudioAdapter& audio);
	void Render(const RenderAdapter& renderer);

private:
	bool resolve;

	std::list<GameObject*> *obj_list;
	std::stack<GameObject*> *add_stack;
	std::stack<GameObject*> *rem_stack;

	void ResolveStack();

};

