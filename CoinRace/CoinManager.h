#pragma once
#include "Map.h"

class CoinManager
{
public:

	int coins,coinsFinal,coinsPlayer;
	Map *myMap;
	CoinManager(Map &m);
	void CoinManager::Manage();
	~CoinManager();
};

