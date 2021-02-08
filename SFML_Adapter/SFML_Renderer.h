#pragma once

#include <SFML/Graphics.hpp>
#include "RenderAdapter.h"

class SFMLRenderer : public RenderAdapter {

public:
	SFMLRenderer(const int& width, const int& height);
	~SFMLRenderer();

	virtual void Clear() override;

	virtual void DrawBlueBox(const float& x, const float& y) const override;
	virtual void DrawRedBox(const float& x, const float& y) const override;
	virtual void DrawGreenBox(const float& x, const float& y) const override;
	virtual void DrawMagentaBox(const float& x, const float& y) const override;

	virtual void DrawUIButton(const float& x, const float& y, const std::string& text) const override;

	virtual void Render() override;

	sf::Sprite GetSprite() const;

private:
	sf::RenderTexture* texture;
	sf::Sprite display_sprite;

	sf::RectangleShape *blue_rect;
	sf::RectangleShape *red_rect;
	sf::RectangleShape *green_rect;
	sf::RectangleShape *magenta_rect;

	float size;

};