#include "Player.h"
#include "Map.h"
#include <iostream>
#include <cstdlib>
#include "Input.hh"



Player::Player()
{
	int i = 0;
	while (i < 1) {
		Player::playerCols = rand() % Map::COLUMNS_MAP;
		Player::playerRows = rand() % Map::ROWS_MAP;
		if (Map::map[playerCols][playerRows].hasCoin == false) {
			Map::map[playerCols][playerRows].symbolToShow = '@';
			Map::map[playerCols][playerRows].isPlayer = true;
		}
	}
}


Player::~Player()
{
}
