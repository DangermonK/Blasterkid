
#include <Game.h>

int main() {

	Game g;

	g.Instantiate(TYPE::TEST, Vector(14, 10));
	g.Instantiate(TYPE::TEST, Vector(5, 5));

	g.Initialize();

	g.Update();

	return 0;
}