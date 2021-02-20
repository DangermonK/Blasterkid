#pragma once
class Texture
{
public:
	Texture();
	Texture(unsigned int tx_index, unsigned int width, unsigned int height);
	~Texture();

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	unsigned int getTextureIndex() const;

private:
	unsigned int width;
	unsigned int height;
	unsigned int tx_index;

};

