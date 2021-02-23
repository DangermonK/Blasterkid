#include "SFML_Renderer.h"

SFMLRenderer::SFMLRenderer(const int& width, const int& height) : RenderAdapter(width, height) {
	texture = new sf::RenderTexture();
	texture->create(width, height);
	display_sprite.setTexture(texture->getTexture());

	font.loadFromFile("arial.ttf");
	text = new sf::Text();
	text->setFont(font);
	text->setCharacterSize(20);
}
SFMLRenderer::~SFMLRenderer() {}

void SFMLRenderer::Clear() {
	texture->clear();
}

void SFMLRenderer::Draw(const Texture& texture) const {
	this->texture->draw(sprite_buffer[texture.getTextureIndex()]);
}

void SFMLRenderer::Draw(const Texture& texture, const float& x, const float& y) const {
	sf::Sprite spr = sprite_buffer[texture.getTextureIndex()];
	spr.setPosition(x, y);
	this->texture->draw(spr);
}

void SFMLRenderer::Draw(const Texture& texture, const float& x, const float& y, const float& scale) const {
	sf::Sprite spr = sprite_buffer[texture.getTextureIndex()];
	spr.setScale(scale, scale);
	spr.setPosition(x, y);
	this->texture->draw(spr);
}

void SFMLRenderer::Draw(const Texture& texture, const float& x, const float& y, const float& scale, const float& alpha) const {
	sf::Sprite spr = sprite_buffer[texture.getTextureIndex()];
	spr.setScale(scale, scale);
	spr.setPosition(x, y);
	spr.setColor(sf::Color(255,255,255,(int)(alpha*255)));
	this->texture->draw(spr);
}

void SFMLRenderer::DrawUIButton(const float& x, const float& y, const std::string& text) const {
	this->text->setFillColor(sf::Color::White);
	this->text->setPosition(x, y);
	this->text->setString(text);
	texture->draw(*this->text);
}

void SFMLRenderer::DrawUIButtonRed(const float& x, const float& y, const std::string& text) const {
	this->text->setFillColor(sf::Color::Red);
	this->text->setPosition(x, y);
	this->text->setString(text);
	texture->draw(*this->text);
}

void SFMLRenderer::Render() {
	texture->display();
}

sf::Sprite SFMLRenderer::GetSprite() const {
	return display_sprite;
}

void SFMLRenderer::ClearCache()
{
	for (auto it = texture_buffer.begin(); it != texture_buffer.end(); it++) {
		delete *it;
	}
	texture_buffer.clear();
	sprite_buffer.clear();
}

Texture SFMLRenderer::LoadFromFile(const std::string& path)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	Texture txt((unsigned int)std::distance(sprite_buffer.begin(), sprite_buffer.end()), texture->getSize().x, texture->getSize().y);
	sprite_buffer.push_back(sf::Sprite(*texture));
	texture_buffer.push_back(texture);
	return txt;
}

