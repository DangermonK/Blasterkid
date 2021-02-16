#pragma once

#include "TextureAtlas.h"
#include <SFML/Graphics.hpp>

#include <string>
#include <fstream>

class SFML_TextureAtlas : public TextureAtlas
{

public:
	SFML_TextureAtlas();
	~SFML_TextureAtlas();

	virtual void loadFromFile(const std::string& path) override;
	virtual const Texture& GetTexture(const int& index) const override;

	sf::Sprite& GetSprite(const Texture& texture);

private:
	sf::Texture txt;
	sf::Sprite spr;

	std::vector<sf::IntRect> rect_vec;
};

