#pragma once
class CoinManager
{
public:

	int coins;
	Map &myMap;
	CoinManager(Map &m);
	void Reset();
	~CoinManager();
};

