#include <iostream>
#include <time.h>
#include <ctime>
#include "Player.h"
#include "Map.h"
#include "CoinManager.h"

int main() {
	srand(time(nullptr));
	int difficulty;
	Input::Key tecla;
	std::cout << "COIN RACE" << std::endl << std::endl << "Controles: WASD" << std::endl << std::endl << std::endl << "Escoge nivel de dificultad:" << std::endl << "Pulsa 1 para nivel facil" << std::endl << "Pulsa 2 para nivel normal" << std::endl << "Pulsa 3 para nivel dificil" << std::endl;

	std::cin >> difficulty;
	Map Mapa(difficulty);
	CoinManager Manager(Mapa);
	Player myPlayer(Mapa, Manager);
	int c = 0;
	std::clock_t t = std::clock();
	Manager.Manage();
	Mapa.PrintMap();
	std::cout << std::endl << "Monedas recogidas: " << myPlayer.getScore() << "/" << Manager.getCoinsFinal() << std::endl << std::endl << "Pulsa la tecla ESC en cualquier momento para salir del juego";
	while (c < 3) {
		if (c == 1) {
			system("CLS");
			std::cout << myPlayer.getScore() << "/" << Manager.getCoinsFinal() << "  Has recogido todas las monedas del nivel en " << t << " segundos." << std::endl << "Pulsa la tecla ESC para salir del juego";
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
				std::cout << std::endl << "Monedas recogidas: " << myPlayer.getScore() << "/" << Manager.getCoinsFinal() << std::endl<< std::endl << "Pulsa la tecla ESC en cualquier momento para salir del juego";
			}
			if (myPlayer.getScore() >= Manager.getCoinsFinal()) {
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