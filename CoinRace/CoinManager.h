#pragma once
#include "Map.h"

class CoinManager
{

private:

	int coins, coinsFinal;

public:

	Map *myMap;
	
	CoinManager(Map &m);

	int getCoinsFinal();
	
	void Manage();
	
	~CoinManager();
};

