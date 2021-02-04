
#include "SceneManager.h"
#include "Scene.h"
#include "SFML_Audio.h"
#include "SFML_Display.h"
#include "SFML_Renderer.h"

class Game : public Scene {

public:
	Game(SceneManager* manager, AudioAdapter& audio) : Scene(manager, audio) {}
	~Game() {}

	virtual void Start() override
	{
		audio.SetMusicVolume(0.5);
		audio.Play("music");
	}

	virtual void Quit() override
	{

	}

	virtual void Update() override
	{
	}

	virtual void Render(const RenderAdapter& r) override
	{
		r.DrawUIButton(r.width * 0.5, 90, "Button");
		r.DrawUIButton(r.width * 0.5, 150, "Button1");
	}

	virtual void HandleInput(const Event& e) override
	{
		switch (e.type) {
		case Event::KEY_DOWN:
			switch (e.key)
			{
			case KeyCode::A: audio.Play("cry"); break;
			case KeyCode::B: audio.Play("car"); break;
			default:
				break;
			}
			break;
		}
	}

};

int main() {

	SFMLDisplay display(400, 400, "test");
	SFMLRenderer* renderer = new SFMLRenderer(400, 400);
	SFMLAudio* audio = new SFMLAudio();
	SceneManager manager(renderer, *audio);
	manager.AddScene<Game>("Game");
	manager.SetScene("Game");
	bool run = true;
	while (run) {
		if (display.IsEvent()) {
			Event e = display.GetEvent();
			switch (e.type) {
			case Event::CLOSED: run = false;  display.Close(); break;
			default: manager.OnInput(e); break;
			}

		}
		manager.Render();
		display.Display(*renderer);
	}

	delete renderer;
	delete audio;

	return 0;
}