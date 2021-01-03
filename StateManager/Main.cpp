
#include <Game.h>

int main() {

	Game g;
	g.Initialize();
	g.Instantiate(TYPE::TESTOBJECT, Vector(10, 10));
	
	while (true) {
		g.Update();
	}

	return 0;
}