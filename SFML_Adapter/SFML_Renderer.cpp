#include "SFML_Renderer.h"

SFMLRenderer::SFMLRenderer(const int& width, const int& height) : RenderAdapter(width, height) {
	texture = new sf::RenderTexture();
	texture->create(width, height);
	display_sprite.setTexture(texture->getTexture());

	blue_rect = new sf::RectangleShape();
	blue_rect->setFillColor(sf::Color::Blue);
	red_rect = new sf::RectangleShape();
	red_rect->setFillColor(sf::Color::Red);
	green_rect = new sf::RectangleShape();
	green_rect->setFillColor(sf::Color::Green);
	magenta_rect = new sf::RectangleShape();
	magenta_rect->setFillColor(sf::Color::Magenta);

	font.loadFromFile("arial.ttf");
	text = new sf::Text();
	text->setFont(font);
	text->setCharacterSize(20);

	size = 20;

}
SFMLRenderer::~SFMLRenderer() {}

void SFMLRenderer::Clear() {
	texture->clear();
}

void SFMLRenderer::DrawBlueBox(const float& x, const float& y) const {
	blue_rect->setSize(sf::Vector2f(size, size));
	blue_rect->setPosition(x * size, y * size);
	texture->draw(*blue_rect);
}

void SFMLRenderer::DrawRedBox(const float& x, const float& y) const {
	red_rect->setSize(sf::Vector2f(size, size));
	red_rect->setPosition(x * size, y * size);
	texture->draw(*red_rect);
}

void SFMLRenderer::DrawGreenBox(const float& x, const float& y) const {
	green_rect->setSize(sf::Vector2f(size, size));
	green_rect->setPosition(x * size, y * size);
	texture->draw(*green_rect);
}

void SFMLRenderer::DrawMagentaBox(const float& x, const float& y) const {
	magenta_rect->setSize(sf::Vector2f(size, size));
	magenta_rect->setPosition(x * size, y * size);
	texture->draw(*magenta_rect);
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

void SFMLRenderer::Render()
{
	texture->display();
}

sf::Sprite SFMLRenderer::GetSprite() const {
	return display_sprite;
}