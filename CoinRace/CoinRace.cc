#include <iostream>
#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <time.h>
#include <ctime>
#include "Input.hh"

int main() {
	srand(time(nullptr));
	Input::Key tecla = Input::Key::W;
	Map Mapa;
	CoinManager Manager(Mapa);
	Player myPlayer(Mapa, Manager);
	int c = 0;
	std::clock_t t = std::clock();
	Manager.Manage();
	Mapa.PrintMap();
	while (c < 3) {
		if (c == 1) {
			system("CLS");
			std::cout << myPlayer.score << "/" << Manager.coinsFinal << "!  Has recogido todas las monedas del nivel en " << t << " segundos." << std::endl;
			c = 2;
		}
		if (c == 2) {
			tecla = Input::getKey();
			if (tecla == Input::Key::ESC)
				c = 3;
		}
		else {
			tecla = Input::getKey();
			if (tecla != Input::Key::NONE && tecla != Input::Key::ESC) {
				myPlayer.Move(tecla);
				Manager.Manage();
				Mapa.PrintMap();
				std::cout << std::endl << "Monedas recogidas: " << myPlayer.score << "/" << Manager.coinsFinal << std::endl;
			}
			if (myPlayer.score >= Manager.coinsFinal) {
				c = 1;
				t = ((std::clock() - t) / (double)CLOCKS_PER_SEC);
			}
			if (tecla == Input::Key::ESC) {
				c = 3;
			}
		}
	}

	return 0;
}