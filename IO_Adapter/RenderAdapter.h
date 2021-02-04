#pragma once

#include <string>

class RenderAdapter {

public:
	RenderAdapter(const int& width, const int& height);
	~RenderAdapter();

	virtual void Clear() = 0;

	// add const methods to draw
	virtual void DrawBox(const float& x, const float& y, const float& w, const float& h) const = 0;
	virtual void DrawUIButton(const float& x, const float& y, const std::string& text) const = 0;

	virtual void Render() = 0;

	const int& width;
	const int& height;

};