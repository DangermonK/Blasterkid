#pragma once

#include "RenderAdapter.h"
#include "Event.h"

template<class T = RenderAdapter>
class DisplayAdapter {

public:
	DisplayAdapter() {}
	virtual ~DisplayAdapter() {}

	virtual void Close() = 0;
	virtual void Display(const T& adapter) = 0;
	virtual bool IsEvent() = 0;
	virtual Event& GetEvent() = 0;

};