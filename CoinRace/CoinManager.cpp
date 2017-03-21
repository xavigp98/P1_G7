/*#include "CoinManager.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>


CoinManager::CoinManager(Map &m):myMap(m)
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

void CoinManager::Reset() {
	if (coins <= 0) {
		CoinManager(myMap);
	}
	else {
		coins = 0;
		for (int i = 0; i < myMap.ROWS_MAP; i++) {
			for (int j = 0; j < myMap.COLUMNS_MAP; j++) {
				if (myMap.map[i][j].hasCoin == true)
					coins += 1;
			}
		}
	}
}


CoinManager::~CoinManager()
{
}
*/