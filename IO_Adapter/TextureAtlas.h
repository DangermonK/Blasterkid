#pragma once

#include <vector>
#include <string>
#include "Texture.h"

class TextureAtlas
{

public:
	TextureAtlas();
	virtual ~TextureAtlas() { }

	virtual void loadFromFile(const std::string& path) = 0;
	virtual const Texture& GetTexture(const int& index) const = 0;

};

