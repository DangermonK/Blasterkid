

#include "Blasterkid_SFML_Launcher.h"

#include <iostream>
#include <thread>
#include <conio.h>


int k = 0;

void A() {
	while (true) {
		k = _getch();
	}
}
void B() {
	while (true) {
		std::cout << k <<"\n";
	}
}

int main() {
		
	auto app = new Blasterkid_SFML_Launcher();
	app->Start();
		
	delete app;

	return 0;
}