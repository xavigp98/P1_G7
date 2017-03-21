#include "CoinManager.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>


CoinManager::CoinManager(Map &m): myMap( m )
{
	coins = (myMap.COLUMNS_MAP * myMap.ROWS_MAP) * 0.3 + rand() % (myMap.COLUMNS_MAP * myMap.ROWS_MAP) * 1.3;

	int i = 0;

	while (i <= coins) {
		int columns = rand() % myMap.COLUMNS_MAP;
		int rows = rand() % myMap.ROWS_MAP;
		if (myMap.map[rows][columns].hasCoin == false && myMap.map[rows][columns].isPlayer == false) {
			myMap.map[rows][columns].hasCoin = true;
			myMap.map[rows][columns].symbolToShow = '$';
			i++;
		}
		else {
		}
	}
}

CoinManager::~CoinManager()
{
}
