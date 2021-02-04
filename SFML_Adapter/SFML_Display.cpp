#include "SFML_Display.h"

SFMLDisplay::SFMLDisplay(const int& width, const int& height, const std::string& title) : DisplayAdapter() {
	frame = new sf::RenderWindow(sf::VideoMode(width, height), title);
	evnt = new sf::Event();
}
SFMLDisplay::~SFMLDisplay() {}

void SFMLDisplay::Close() {
	frame->close();
}

void SFMLDisplay::Display(const SFMLRenderer& adapter) {
	frame->clear();
	frame->draw(adapter.GetSprite());
	frame->display();
}

bool SFMLDisplay::IsEvent() {
	return frame->pollEvent(*evnt);
}

Event& SFMLDisplay::GetEvent() {
	Event& e = *new Event();
	switch (evnt->type) {
	case sf::Event::Closed: e.type = Event::CLOSED; break;
	case sf::Event::KeyPressed:
		e.type = Event::KEY_DOWN;
		switch (evnt->key.code)
		{
		case sf::Keyboard::A: e.key = KeyCode::A; break;
		case sf::Keyboard::B: e.key = KeyCode::B; break;
		case sf::Keyboard::C: e.key = KeyCode::C; break;
		case sf::Keyboard::D: e.key = KeyCode::D; break;
		default: e.key = KeyCode::UNKNOWN; break;
		}
		break;
	case sf::Event::KeyReleased: e.type = Event::KEY_UP; break;
	default: e.type = Event::UNKNOWN; break;
	}
	return e;
}