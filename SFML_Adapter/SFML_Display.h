#pragma once

#include <SFML/Graphics.hpp>
#include "DisplayAdapter.h"
#include "SFML_Renderer.h"

class SFMLDisplay : public DisplayAdapter<SFMLRenderer> {

public:
	SFMLDisplay(const int& width, const int& height, const std::string& title);
	~SFMLDisplay();

	virtual void Close() override;

	virtual void Display(const SFMLRenderer& adapter) override;

	virtual bool IsEvent() override;

	virtual Event& GetEvent() override;

private:
	sf::RenderWindow* frame;
	sf::Event* evnt;

};