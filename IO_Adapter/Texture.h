#pragma once
class Texture
{
public:
	Texture(const unsigned int& tx_index, const unsigned int& width, const unsigned int& height);
	~Texture();

	const unsigned int getWidth() const;
	const unsigned int getHeight() const;
	const unsigned int getTextureIndex() const;

private:
	const unsigned int width;
	const unsigned int height;
	const unsigned int tx_index;

};

