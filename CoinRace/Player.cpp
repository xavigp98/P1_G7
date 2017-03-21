/*#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <iostream>
#include <cstdlib>
#include "Input.hh"



Player::Player(Map &m, CoinManager &p):myMap(m),myManager(p)
{
	int i = 0;
	while (i < 1) {
		playerCols = rand() % myMap.COLUMNS_MAP;
		playerRows = rand() % myMap.ROWS_MAP;
		if (myMap.map[playerCols][playerRows].hasCoin == false) {
			myMap.map[playerCols][playerRows].symbolToShow = '@';
			myMap.map[playerCols][playerRows].isPlayer = true;
		}
	}
}


Player::~Player()
{
}*/
