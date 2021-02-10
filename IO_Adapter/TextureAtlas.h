#pragma once

#include <vector>
#include <string>
#include "Texture.h"


class TextureAtlas
{

public:
	TextureAtlas(const std::string& path);
	~TextureAtlas();

	const Texture& GetTexture(const int& index) const;

};

