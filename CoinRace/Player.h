#pragma once
#include "Map.h"
#include "CoinManager.h"
#include "Input.hh"
class Player
{
public:
	int playerCols, playerRows, score;
	Map *myMap;
	CoinManager *myManager;
	Player(Map &m, CoinManager &p);
	void Move(Input::Key key);
	~Player();
};

