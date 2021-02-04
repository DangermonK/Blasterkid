#pragma once

#include <SFML/Graphics.hpp>
#include "RenderAdapter.h"

class SFMLRenderer : public RenderAdapter {

public:
	SFMLRenderer(const int& width, const int& height);
	~SFMLRenderer();

	virtual void Clear() override;

	virtual void DrawBox(const float& x, const float& y, const float& w, const float& h) const override;

	virtual void DrawUIButton(const float& x, const float& y, const std::string& text) const override;

	virtual void Render() override;

	sf::Sprite GetSprite() const;

private:
	sf::RenderTexture* texture;
	sf::Sprite display_sprite;

	sf::RectangleShape* rect_shape;
	sf::Text* text;
	sf::Font font;

};