#pragma once
#include "Map.h"
#include "CoinManager.h"
class Player
{
public:
	int playerCols, playerRows, c;
	Map *myMap;
	CoinManager *myManager;
	Player(Map &m, CoinManager &p);
	void PlayerInput();
	~Player();
};

