#include "CoinManager.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>


CoinManager::CoinManager()
{
	CoinManager::coins = (Map::COLUMNS_MAP * Map::ROWS_MAP) * 0.3 + rand() % (Map::COLUMNS_MAP * Map::ROWS_MAP) * 1.3;

	int i = 0;

	while (i <= CoinManager::coins) {
		int columns = rand() % Map::COLUMNS_MAP;
		int rows = rand() % Map::ROWS_MAP;
		if (Map::map[rows][columns].hasCoin == false && Map::map[rows][columns].isPlayer == false) {
			Map::map[rows][columns].hasCoin = true;
			Map::map[rows][columns].symbolToShow = '$';
			i++;
		}
		else {
		}
	}
}

void CoinManager::Reset() {
	if (CoinManager::coins <= 0) {
		CoinManager::CoinManager();
	}
	else {
		CoinManager::coins = 0;
		for (int i = 0; i < Map::ROWS_MAP; i++) {
			for (int j = 0; j < Map::COLUMNS_MAP; j++) {
				if (Map::map[i][j].hasCoin == true)
					CoinManager::coins += 1;
			}
		}
	}
}


CoinManager::~CoinManager()
{
}
