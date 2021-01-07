#pragma once

#include <iostream>

class DisplayAdapter
{

public:
	DisplayAdapter();
	~DisplayAdapter();

	virtual void ClearDisplay() = 0;
	virtual void DrawText(const std::string& text) = 0;
	virtual void DrawRect(const float& x, const float& y, const float& w, const float &h) = 0;
	virtual void Display() = 0;

};

