#include "SFML_Renderer.h"

SFMLRenderer::SFMLRenderer(const int& width, const int& height) : RenderAdapter(width, height) {
	texture = new sf::RenderTexture();
	texture->create(width, height);
	display_sprite.setTexture(texture->getTexture());

	rect_shape = new sf::RectangleShape();
	text = new sf::Text();

	font.loadFromFile("arial.ttf");
	this->text->setFont(font);

}
SFMLRenderer::~SFMLRenderer() {}

void SFMLRenderer::Clear() {
	texture->clear();
}

void SFMLRenderer::DrawBox(const float& x, const float& y, const float& w, const float& h) const {
	rect_shape->setPosition(x, y);
	rect_shape->setSize(sf::Vector2f(w, h));
	texture->draw(*rect_shape);
}

void SFMLRenderer::DrawUIButton(const float& x, const float& y, const std::string& text) const {

	this->text->setString(text);
	this->text->setCharacterSize(20);
	this->text->setPosition(x + this->text->getCharacterSize() * 0.5, y + this->text->getCharacterSize() * 0.4);
	this->text->setFillColor(sf::Color::Red);
	int width = (text.length() * this->text->getCharacterSize()) * 0.5;
	DrawBox(x, y, width + this->text->getCharacterSize(), this->text->getCharacterSize() * 2);
	texture->draw(*this->text);
}

void SFMLRenderer::Render()
{
	texture->display();
}

sf::Sprite SFMLRenderer::GetSprite() const {
	return display_sprite;
}