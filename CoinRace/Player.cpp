#include "Player.h"
#include <iostream>
#include <cstdlib>




Player::Player(Map &m, CoinManager &p):myMap(&m),myManager(&p)
{
	int i = 0;
	while (i < 1) {
		playerCols = rand() % myMap->getMapCols();
		playerRows = rand() % myMap->getMapRows();
		if (myMap->getPos(playerRows,playerCols) =='.') {
			myMap->Modify(playerRows, playerCols, '@');
			i++;
		}
	}
	score = 0;
}

void Player::Move(Input::Key key) {
	switch (key)
	{
	case Input::Key::W:
		if ( (playerRows - 1) >= 0) {
			if (myMap->getPos(playerRows - 1,playerCols) == '$')
				score++;
			myMap->Modify(playerRows, playerCols, '.');
			myMap->Modify(playerRows-1, playerCols, '@');
			
			playerRows -= 1;
		}
		break;
	case Input::Key::A:
		if ( (playerCols - 1) >= 0) {
			if (myMap->getPos(playerRows,playerCols - 1) == '$')
				score++;
			myMap->Modify(playerRows, playerCols, '.');
			myMap->Modify(playerRows, playerCols-1, '@');
			playerCols -= 1;
		}
		break;
	case Input::Key::S:
		if ( playerRows+1 < myMap->getMapRows()) {
			if (myMap->getPos(playerRows + 1,playerCols) == '$')
				score++;
			myMap->Modify(playerRows, playerCols, '.');
			myMap->Modify(playerRows + 1, playerCols, '@');
			playerRows += 1;
		}
		break;
	case Input::Key::D:
		if ( playerCols + 1 < myMap->getMapCols()) {
			if (myMap->getPos(playerRows,playerCols + 1) == '$')
				score++;
			myMap->Modify(playerRows, playerCols, '.');
			myMap->Modify(playerRows, playerCols + 1, '@');
			playerCols += 1;
		}
		break;
	default:
		break;
	}
}

int Player::getScore() {
	return score;
}

Player::~Player()
{
}
