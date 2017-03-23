#include <iostream>
#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <time.h>
#include "Input.hh"

int main() {
	srand(time(nullptr));
	Input::Key tecla;
	Map Mapa;
	CoinManager Manager(Mapa);
	Player myPlayer(Mapa, Manager);
	int c = 0;
	while (c < 1) {
		Mapa.PrintMap();
		Manager.Manage();
		myPlayer.PlayerInput();
		if (Manager.coinsFinal == Manager.coinsPlayer) {
			c = 1;
		}
	}
	return 0;
}