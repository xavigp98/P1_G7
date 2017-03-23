#include "Player.h"
#include "Map.h"
#include "CoinManager.h"
#include <iostream>
#include <cstdlib>
#include "Input.hh"



Player::Player(Map &m, CoinManager &p):myMap(&m),myManager(&p)
{
	int i = 0;
	c = 0;
	while (i < 1) {
		playerCols = rand() % myMap->COLUMNS_MAP;
		playerRows = rand() % myMap->ROWS_MAP;
		if (myMap->map[playerRows][playerCols].hasCoin == false) {
			myMap->map[playerRows][playerCols].symbolToShow = '@';
			myMap->map[playerRows][playerCols].isPlayer = true;
			i++;
		}
	}
	
}

void Player::PlayerInput() {
	switch (Input::getKey())
	{
	case Input::Key::W:
		if (myMap->map[playerRows - 1][playerCols].hasCoin == false || myMap->map[playerRows-1][playerCols].hasCoin == true && (playerRows - 1) >= 0) {
			myMap->map[playerRows ][playerCols].hasCoin = false;
			myMap->map[playerRows ][playerCols].symbolToShow = '.';
			myMap->map[playerRows ][playerCols].isPlayer = false;
			myMap->map[playerRows - 1][playerCols].hasCoin = false;
			myMap->map[playerRows - 1][playerCols].symbolToShow = '@';
			myMap->map[playerRows - 1][playerCols].isPlayer = true;
			playerRows -= 1;
		}
		break;
	case Input::Key::A:
		if (myMap->map[playerRows][playerCols-1].hasCoin == false || myMap->map[playerRows][playerCols-1].hasCoin == true && playerCols - 1 >= myMap->COLUMNS_MAP - myMap->COLUMNS_MAP) {
			myMap->map[playerRows][playerCols].hasCoin = false;
			myMap->map[playerRows][playerCols].symbolToShow = '.';
			myMap->map[playerRows][playerCols].isPlayer = false;
			myMap->map[playerRows][playerCols-1].hasCoin = false;
			myMap->map[playerRows][playerCols-1].symbolToShow = '@';
			myMap->map[playerRows][playerCols-1].isPlayer = true;
			playerCols -= 1;
		}
		break;
	case Input::Key::S:
		if (myMap->map[playerRows + 1 ][playerCols].hasCoin == false || myMap->map[playerRows + 1][playerCols].hasCoin == true && playerRows + 1 < myMap->ROWS_MAP) {
			myMap->map[playerRows][playerCols].hasCoin = false;
			myMap->map[playerRows][playerCols].symbolToShow = '.';
			myMap->map[playerRows][playerCols].isPlayer = false;
			myMap->map[playerRows+1][playerCols].hasCoin = false;
			myMap->map[playerRows+1][playerCols].symbolToShow = '@';
			myMap->map[playerRows+1][playerCols].isPlayer = true;
			playerRows += 1;
		}
		break;
	case Input::Key::D:
		if (myMap->map[playerRows][playerCols+1].hasCoin == false || myMap->map[playerRows][playerCols+1].hasCoin == true && playerCols + 1 < myMap->COLUMNS_MAP) {
			myMap->map[playerRows][playerCols].hasCoin = false;
			myMap->map[playerRows][playerCols].symbolToShow = '.';
			myMap->map[playerRows][playerCols].isPlayer = false;
			myMap->map[playerRows][playerCols+1].hasCoin = false;
			myMap->map[playerRows][playerCols+1].symbolToShow = '@';
			myMap->map[playerRows][playerCols+1].isPlayer = true;
			playerCols += 1;
		}
		break;
	case Input::Key::ESC:
		c = 1;
	default:
		break;
	}

	if (myManager->coinsPlayer == myManager->coinsPlayer)
		c = 1;
}


Player::~Player()
{
	delete myManager;
	delete myMap;
}
