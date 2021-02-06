
#include "SceneManager.h"
#include "Scene.h"
#include "SFML_Audio.h"
#include "SFML_Display.h"
#include "SFML_Renderer.h"

#include <ctime>
#include <random>
#include <iostream>

enum class MapType { FLOOR, WALL, DETSRUCTABLE, COUNT };

class GridMap {
	
public:
	GridMap(const int& rows, const int& cols) : rows(rows), cols(cols) {
		const int size = rows * cols;
		map = new MapType[size];
		for (int i = 0; i < size; i++) {
			map[(int)(i / rows) * rows + (i % cols)] = (MapType)(rand() % (int)MapType::COUNT);
		}
	}

	~GridMap() {}

	const MapType& GetCell(const int& x, const int& y) const {
		return (CheckCell(x, y) ? map[y * rows + x] : MapType::WALL);
	}

	void SetCell(const int& x, const int& y, const MapType& value) const {
		if (CheckCell(x, y)) {
			map[y * rows + x] = value;
		}
	}

	int GetRows() { return rows; }
	int GetCols() { return cols; }

private:
	MapType* map;
	const int rows;
	const int cols;

	bool CheckCell(const int& x, const int& y) const {
		return x >= 0 && x < cols && y >= 0 && y < rows;
	}

};

class GridMovement {

public:
	GridMovement(const int& x, const int& y, const float& speed, const GridMap& map, AudioAdapter& audio) : map(map), audio(audio) {
		this->x = lx = x;
		this->y = ly = y;
		this->dx = this->dy = 0;
		this->l = this->r = this->u = this->d = false;
		this->interpolation = 0;
		this->speed = speed;
	}
	~GridMovement() {}

	void Move(const float& delta) {
		if (dx != 0 || dy != 0) {
			interpolation += delta * speed;
			if (interpolation >= 1) {
				lx = x;
				ly = y;
				if (map.GetCell(x + dx, y) == MapType::DETSRUCTABLE) {
					map.SetCell(x + dx, y, MapType::FLOOR);
					audio.Play("");
				}
				if (map.GetCell(x, y + dy) == MapType::DETSRUCTABLE) {
					map.SetCell(x, y + dy, MapType::FLOOR);
					audio.Play("");

				}
				if (dy == 0 && map.GetCell(x + dx, y) == MapType::FLOOR)
					x += dx;
				if (dx == 0 && map.GetCell(x, y + dy) == MapType::FLOOR)
					y += dy;

				interpolation = 0;
				CheckMovement();
			}
		}
	}

	void MoveRight(const bool& v) { 
		r = v;
		CheckMovement();
	}
	void MoveLeft(const bool& v) { 
		l = v;
		CheckMovement();
	}
	void MoveUp(const bool& v) {
		u = v;
		CheckMovement();
	}
	void MoveDown(const bool& v) {
		d = v; 
		CheckMovement();
	}

	const float& getInterpolatedX() {
		return lx + (x - lx) * interpolation;
	}
	const float& getInterpolatedY() {
		return ly + (y - ly) * interpolation;
	}

	const float& getX() { return x; }
	const float& getY() { return y; }
	const float& getLastX() { return lx; }
	const float& getLastY() { return ly; }

private:
	int x, y, lx, ly, dx, dy;
	bool r, l, u, d;
	float interpolation, speed;

	const GridMap& map;
	AudioAdapter& audio;

	void FlipRL() { int nx = lx; lx = x; x = nx; interpolation = 1 - interpolation; }
	void FlipUD() { int ny = ly; ly = y; y = ny; interpolation = 1 - interpolation; }

	void CheckMovement() {
		if (r) {
			if (x - lx < 0) { FlipRL(); }
			dx = 1;
		}
		else if (l) {
			if (x - lx > 0) { FlipRL(); }
			dx = -1;
		}
		else {
			dx = 0;
		}
		if (u) {
			if (y - ly > 0) { FlipUD(); }
			dy = -1;
		}
		else if (d) {
			if (y - ly < 0) { FlipUD(); }
			dy = 1;
		}
		else {
			dy = 0;
		}
		if (lx == x && ly == y) interpolation = 1;
	}
};

class Test : public Scene {
	
public:
	Test(SceneManager* manager, AudioAdapter& audio) : Scene(manager, audio) {
		map = new GridMap(20, 20);
		movement = new GridMovement(5, 5, 5, *map, audio);
	}
	~Test() {}

	virtual void Start() override
	{
		now = std::clock();
	}

	virtual void Quit() override
	{
	}

	virtual void Update() override
	{
		last = now;
		now = (float)std::clock();
		delta = (now - last) / CLOCKS_PER_SEC;

		movement->Move(delta);

	}

	int size = 40;

	virtual void Render(const RenderAdapter& r) override
	{
		for (int i = 0; i < map->GetRows(); i++)
			for (int j = 0; j < map->GetRows(); j++) {
				if (map->GetCell(j, i) == MapType::FLOOR)
					r.DrawGreenBox(j * size, i * size, size, size);
				else if (map->GetCell(j, i) == MapType::DETSRUCTABLE)
					r.DrawRedBox(j * size, i * size, size, size);
			}

		//r.DrawRedBox(movement->lx * size, movement->ly * size, size, size);
		r.DrawBlueBox(movement->getInterpolatedX() * size, movement->getInterpolatedY() * size, size, size);
	}

	virtual void HandleInput(const Event& e) override
	{
		switch (e.type)
		{
		case Event::KEY_DOWN: 
			switch (e.key)
			{
			case KeyCode::UP: movement->MoveUp(true); break;
			case KeyCode::DOWN: movement->MoveDown(true); break;
			case KeyCode::LEFT: movement->MoveLeft(true); break;
			case KeyCode::RIGHT: movement->MoveRight(true); break;
			default:
				break;
			} 
			break;

		case Event::KEY_UP:
			switch (e.key)
			{
			case KeyCode::UP: movement->MoveUp(false); break;
			case KeyCode::DOWN: movement->MoveDown(false); break;
			case KeyCode::LEFT: movement->MoveLeft(false); break;
			case KeyCode::RIGHT: movement->MoveRight(false); break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

private:
	float now;
	float last;
	float delta;

	float counter = 0;
	GridMovement *movement;
	GridMap *map;


};

int main() {

	SFMLDisplay display(800, 800, "test");
	SFMLRenderer* renderer = new SFMLRenderer(800, 800);
	SFMLAudio* audio = new SFMLAudio();
	SceneManager manager(renderer, *audio);
	manager.AddScene<Test>("Start");
	manager.SetScene("Start");
	bool run = true;
	while (run) {
		if (display.IsEvent()) {
			Event e = display.GetEvent();
			switch (e.type) {
			case Event::CLOSED: run = false;  display.Close(); break;
			default: manager.OnInput(e); break;
			}

		}
		manager.Update();
		manager.Render();
		display.Display(*renderer);
	}

	delete renderer;
	delete audio;

	return 0;
}