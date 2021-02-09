#pragma once

#include "SFML_Renderer.h"
#include "SFML_Display.h"
#include "SFML_Audio.h"
#include "Application.h"

#include "GameScene.h"
#include "Menu.h"

class Blasterkid_SFML_Launcher : public Application<SFMLRenderer, SFMLDisplay, SFMLAudio> {
	
public:
	Blasterkid_SFML_Launcher() : Application(600, 600, "Blasterkid Game") {
	}
	~Blasterkid_SFML_Launcher() {}

private:
	virtual void Initialize(SceneManager* scm) override {
		scm->AddScene<Test>("Start");
		scm->AddScene<GameMenu>("GameMenu");
		scm->SetScene("GameMenu");
	}

};