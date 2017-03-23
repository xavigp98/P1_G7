#include "CoinManager.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>


CoinManager::CoinManager(Map &m, int difficulty):myMap(&m)
{
	coins = (static_cast<int>(myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.03 )+ rand() % static_cast<int>(((myMap->COLUMNS_MAP * myMap->ROWS_MAP) * 0.13)- (myMap->COLUMNS_MAP * myMap->ROWS_MAP)*0.03);

	coinsFinal = 30 * myMap->difficulty + rand() % ((30 *myMap->difficulty * 2) - (30 * myMap->difficulty));

	int i = 0;

	while (i < coins) {
		int columns = rand() % myMap->COLUMNS_MAP;
		int rows = rand() % myMap->ROWS_MAP;
		if (myMap->getPos(rows,columns)=='.') {
			myMap->Modify(rows,columns,'$');
			i++;
		}
	}
}

void CoinManager::Manage() {
	int c = 0;
	for (int i = 0; i < myMap->ROWS_MAP; i++) {
		for (int j = 0; j < myMap->COLUMNS_MAP; j++) {
			if (myMap->getPos(i,j) == '$') {
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
			if (myMap->getPos(rows,columns) == '.') {
				myMap->Modify(rows,columns,'$');
				i++;
			}
		}
	}
	coins = c;
}

CoinManager::~CoinManager()
{
}
