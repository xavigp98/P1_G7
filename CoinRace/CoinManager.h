#pragma once
#include "Map.h"

class CoinManager
{
public:

	int coins,coinsFinal;
	Map *myMap;
	CoinManager(Map &m, int difficulty);
	void CoinManager::Manage();
	~CoinManager();
};

