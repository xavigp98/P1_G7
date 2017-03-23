#include "CoinManager.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>


CoinManager::CoinManager(Map &m):myMap(&m)
{
	coins = (static_cast<int>(myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.03 )+ rand() % static_cast<int>(((myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.13)- (myMap->COLUMNS_MAP * myMap->ROWS_MAP)*0.03);

	coinsFinal = 30 * myMap->difficulty + rand() % ((30 * myMap->difficulty * 2) - (30 * myMap->difficulty));

	int i = 0;

	while (i < coins) {
		int columns = rand() % myMap->COLUMNS_MAP;
		int rows = rand() % myMap->ROWS_MAP;
		if (myMap->map[rows][columns].hasCoin == false && myMap->map[rows][columns].isPlayer == false) {
			myMap->map[rows][columns].hasCoin = true;
			myMap->map[rows][columns].symbolToShow = '$';
			i++;
		}
		else {
		}
	}
	coinsPlayer = 0;
}

void CoinManager::Manage() {
	int c = 0;
	for (int i = 0; i < myMap->ROWS_MAP; i++) {
		for (int j = 0; j < myMap->COLUMNS_MAP; j++) {
			if (myMap->map[i][j].hasCoin == true) {
				c += 1;
			}

		}
	}
	if (c <= 0) {
		int i = 0;
		coins = (static_cast<int>(myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.03) + rand() % static_cast<int>(((myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.13) - (myMap->COLUMNS_MAP * myMap->ROWS_MAP)*0.03);

		while (i < coins) {
			int columns = rand() % myMap->COLUMNS_MAP;
			int rows = rand() % myMap->ROWS_MAP;
			if (myMap->map[rows][columns].hasCoin == false && myMap->map[rows][columns].isPlayer == false) {
				myMap->map[rows][columns].hasCoin = true;
				myMap->map[rows][columns].symbolToShow = '$';
				i++;
			}
			else {
			}
		}
	}
	if (c < coins)
		coinsPlayer++;
	coins = c;
	std::cout << std::endl << "Has recogido: " << coinsPlayer << "/" << coinsFinal;
}

CoinManager::~CoinManager()
{
	delete myMap;
}
