#pragma once
#include "Map.h"

class CoinManager
{
public:

	int coins;
	Map *myMap;
	CoinManager(Map &m);
	~CoinManager();
};

