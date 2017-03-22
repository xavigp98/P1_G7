#include "CoinManager.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>


CoinManager::CoinManager(Map &m):myMap(&m)
{
	coins = (static_cast<int>(myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.03 )+ rand() % static_cast<int>(((myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.13)- (myMap->COLUMNS_MAP * myMap->ROWS_MAP)*0.03);

	int i = 0;

	while (i <= coins) {
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

CoinManager::~CoinManager()
{
	delete myMap;
}
