#include "CoinManager.h"
#include <iostream>
#include <cstdlib>


CoinManager::CoinManager(Map &m):myMap(&m)
{
	coins = (static_cast<int>(myMap->getMapCols() * myMap->getMapRows()) * 0.03 )+ rand() % static_cast<int>(((myMap->getMapCols() * myMap->getMapRows()) * 0.13)- (myMap->getMapCols() * myMap->getMapRows())*0.03);

	coinsFinal = 30 * myMap->getDifficulty() + rand() % ((30 *myMap->getDifficulty() * 2) - (30 * myMap->getDifficulty()));

	int i = 0;

	while (i < coins) {
		int columns = rand() % myMap->getMapCols();
		int rows = rand() % myMap->getMapRows();
		if (myMap->getPos(rows,columns)=='.') {
			myMap->Modify(rows,columns,'$');
			i++;
		}
	}
}

void CoinManager::Manage() {
	int c = 0;
	for (int i = 0; i < myMap->getMapRows(); i++) {
		for (int j = 0; j < myMap->getMapCols(); j++) {
			if (myMap->getPos(i,j) == '$') {
				c += 1;
			}

		}
	}
	if (c <= 0) {
		int i = 0;
		coins = (static_cast<int>(myMap->getMapCols() * myMap->getMapRows()) * 0.03) + rand() % static_cast<int>(((myMap->getMapCols() * myMap->getMapRows()) * 0.13) - (myMap->getMapCols() * myMap->getMapRows())*0.03);

		while (i < coins) {
			int columns = rand() % myMap->getMapCols();
			int rows = rand() % myMap->getMapRows();
			if (myMap->getPos(rows,columns) == '.') {
				myMap->Modify(rows,columns,'$');
				i++;
			}
		}
	}
	coins = c;
}

int CoinManager::getCoinsFinal() {
	return coinsFinal;
}

CoinManager::~CoinManager()
{
}
