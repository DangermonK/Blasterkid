#include "SFML_Display.h"

SFMLDisplay::SFMLDisplay(const int& width, const int& height, const std::string& title) : DisplayAdapter(width, height, title) {
	frame = new sf::RenderWindow(sf::VideoMode(width, height), title);
	frame->setVerticalSyncEnabled(true);
	evnt = new sf::Event();
}
SFMLDisplay::~SFMLDisplay() {
	delete frame;
	delete evnt;
}

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

KeyCode MapKey(sf::Event::KeyEvent e) {
	switch (e.code)
	{
	case sf::Keyboard::W: return KeyCode::W;
	case sf::Keyboard::A: return KeyCode::A;
	case sf::Keyboard::S: return KeyCode::S;
	case sf::Keyboard::D: return KeyCode::D;
	case sf::Keyboard::Up: return KeyCode::UP;
	case sf::Keyboard::Down: return KeyCode::DOWN;
	case sf::Keyboard::Left: return KeyCode::LEFT;
	case sf::Keyboard::Right: return KeyCode::RIGHT;
	case sf::Keyboard::LShift: return KeyCode::LEFT_SHIFT;
	case sf::Keyboard::RShift: return KeyCode::RIGHT_SHIFT;
	case sf::Keyboard::LControl: return KeyCode::LEFT_CTRL;
	case sf::Keyboard::RControl: return KeyCode::RIGHT_CTRL;
	case sf::Keyboard::Space: return KeyCode::SPACE;
	case sf::Keyboard::Return: return KeyCode::RETURN;
	case sf::Keyboard::Escape: return KeyCode::ESCAPE;
	default: return KeyCode::UNKNOWN;
	}
}

Event& SFMLDisplay::GetEvent() {
	Event& e = *new Event();
	switch (evnt->type) {
	case sf::Event::Closed: e.type = Event::CLOSED; break;
	case sf::Event::KeyPressed:
		e.type = Event::KEY_DOWN;
		e.key = MapKey(evnt->key);
		break;
	case sf::Event::KeyReleased:
		e.type = Event::KEY_UP;
		e.key = MapKey(evnt->key);
		break;
	default: e.type = Event::UNKNOWN; break;
	}
	return e;
}