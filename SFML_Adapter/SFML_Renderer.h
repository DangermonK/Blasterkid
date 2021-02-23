#pragma once

#include <SFML/Graphics.hpp>
#include "RenderAdapter.h"

class SFMLRenderer : public RenderAdapter {

public:
	SFMLRenderer(const int& width, const int& height);
	~SFMLRenderer();

	virtual Texture LoadFromFile(const std::string& path) override;

	virtual void ClearCache() override;

	virtual void Clear() override;

	virtual void Draw(const Texture& texture) const override;
	virtual void Draw(const Texture& texture, const float& x, const float& y) const override;
	virtual void Draw(const Texture& texture, const float& x, const float& y, const float& scale) const override;
	virtual void Draw(const Texture& texture, const float& x, const float& y, const float& scale, const float& alpha) const override;

	virtual void DrawUIButton(const float& x, const float& y, const std::string& text) const override;
	virtual void DrawUIButtonRed(const float& x, const float& y, const std::string& text) const override;

	virtual void Render() override;

	sf::Sprite GetSprite() const;

private:
	std::vector<sf::Sprite> sprite_buffer;
	std::vector<sf::Texture*> texture_buffer;

	sf::RenderTexture* texture;
	sf::Sprite display_sprite;

	sf::Font font;
	sf::Text *text;

};