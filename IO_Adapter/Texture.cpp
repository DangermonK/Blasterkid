#include "Texture.h"

Texture::Texture() : tx_index(0), width(0), height(0) {}
Texture::Texture(unsigned int tx_index, unsigned int width, unsigned int height) : tx_index(tx_index), width(width), height(height) {}
Texture::~Texture() {}

unsigned int Texture::getWidth() const { return width; }
unsigned int Texture::getHeight() const { return height; }
unsigned int Texture::getTextureIndex() const { return tx_index; }

	