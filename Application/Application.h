#pragma once

#include "RenderAdapter.h"
#include "DisplayAdapter.h"
#include "AudioAdapter.h"
#include "SceneManager.h"

#include "Timer.h"

template<class R = RenderAdapter, class D = DisplayAdapter<R>, class A = AudioAdapter>
class Application {

public:
	Application(const int& width, const int& height, const std::string& title) {
		disp = new D(width, height, title);
		rnd = new R(width, height);
		aud = new A();
		scm = new SceneManager(*rnd, *aud);
	}
	virtual ~Application() {
		delete disp;
		delete rnd;
		delete aud;
		delete scm;
	}

	void Start() {
		Initialize(scm);
		scm->Start();
		Run();
	}

protected:
	SceneManager* scm;

private:
	D* disp;
	R* rnd;
	A* aud;
	
	virtual void Initialize(SceneManager* scm) = 0;

	void Run() {
		while (scm->IsRunning()) {
			Timer::RefreshTimer();
			if (disp->IsEvent()) {
				Event e = disp->GetEvent();
				switch (e.type) {
				case Event::CLOSED: scm->Stop();  disp->Close(); return;
				default: scm->OnInput(e); break;
				}
				
			}
			scm->Update();
			scm->Render();
			disp->Display(*rnd);
		}
	}

};