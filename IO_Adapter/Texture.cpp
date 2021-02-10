#include "Texture.h"

Texture::Texture(const unsigned int& tx_index, const unsigned int& width, const unsigned int& height) : tx_index(tx_index), width(width), height(height) {}
Texture::~Texture() {}

const unsigned int Texture::getWidth() const { return width; }
const unsigned int Texture::getHeight() const { return height; }
const unsigned int Texture::getTextureIndex() const { return tx_index; }

	