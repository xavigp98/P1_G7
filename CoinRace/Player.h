#pragma once
#include "Map.h"
#include "CoinManager.h"
#include "Input.hh"
class Player
{

private:
	
	int playerCols, playerRows, score;

public:
	
	Map *myMap;
	
	CoinManager *myManager;
	
	Player(Map &m, CoinManager &p);
	
	void Move(Input::Key key);

	int getScore();
	
	~Player();
};

