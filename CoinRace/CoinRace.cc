#include <iostream>
//#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <time.h>

int main() {
	srand(time(nullptr));
	Map Mapa;
	CoinManager Manager(Mapa);
	Mapa.PrintMap();
	return 0;
}