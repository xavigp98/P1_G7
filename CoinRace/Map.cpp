#include "Map.h"
#include <iostream>
#include <cstdlib>



Map::Map()
{
	std::cout << "Escoge nivel de dificultad:" << std::endl << "Pulsa 1 para nivel facil" << std::endl << "Pulsa 2 para nivel normal" << std::endl << "Pulsa 3 para nivel dificil" << std::endl;

	std::cin >>difficulty;

	ROWS_MAP = 5 * difficulty + rand() % ((5 * difficulty * 2) - (5 * difficulty));
	COLUMNS_MAP = 5 *difficulty + rand() % ((5 * difficulty * 2) - (5 * difficulty));

	map = new cell*[Map::ROWS_MAP];

	for (int i = 0; i < ROWS_MAP; i++) {
		map[i] = new cell[COLUMNS_MAP];
	}

	for (int i = 0; i < ROWS_MAP; i++) {
		for (int j = 0; j < COLUMNS_MAP; j++) {
			map[i][j].hasCoin = false;
			map[i][j].isPlayer = false;
			map[i][j].symbolToShow = '.';
			map[i][j].NUM_COLUMN = j;
			map[i][j].NUM_ROW = i;
		}
	}
}

void Map::Modify(int ROW, int COL, char value) {
	map[ROW][COL].symbolToShow = value;
	if (value == '$')
		map[ROW][COL].hasCoin = true;
	else
		map[ROW][COL].hasCoin = false;
}

void Map::PrintMap() {
	for (int i = 0; i < ROWS_MAP; i++) {
		for (int j = 0; j < COLUMNS_MAP; j++) {
			std::cout << map[i][j].symbolToShow;
		}
		std::cout << std::endl;
	}
}

Map::~Map()
{
}
