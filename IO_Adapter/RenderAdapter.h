#pragma once

#include "Texture.h"
#include <string>

class RenderAdapter {

public:
	RenderAdapter(const int& width, const int& height);
	virtual ~RenderAdapter();

	virtual Texture LoadFromFile(const std::string& path) = 0;
	virtual void ClearCache() = 0;

	virtual void Clear() = 0;

	virtual void Draw(const Texture& texture) const = 0;
	virtual void Draw(const Texture& texture, const float& x, const float& y) const = 0;
	virtual void Draw(const Texture& texture, const float& x, const float& y, const float& scale) const = 0;
	virtual void DrawBlueBox(const float& x, const float& y) const = 0;
	virtual void DrawRedBox(const float& x, const float& y) const = 0;
	virtual void DrawGreenBox(const float& x, const float& y) const = 0;
	virtual void DrawMagentaBox(const float& x, const float& y) const = 0;
	virtual void DrawUIButton(const float& x, const float& y, const std::string& text) const = 0;
	virtual void DrawUIButtonRed(const float& x, const float& y, const std::string& text) const = 0;

	virtual void Render() = 0;

	const int GetWidth();
	const int GetHeight();

private:
	const int width;
	const int height;

};