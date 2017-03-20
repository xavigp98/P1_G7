#include "Map.h"
#include <iostream>
#include <cstdlib>



Map::Map()
{
	std::cout << "Escoge nivel de dificultad:" << std::endl << "Pulsa 1 para nivel facil" << std::endl << "Pulsa 2 para nivel normal" << std::endl << "Pulsa 3 para nivel dificil" << std::endl;

	std::cin >> Map::difficulty;

	Map::ROWS_MAP = 5 * Map::difficulty + rand() % ((5 * Map::difficulty * 2) - (5 * Map::difficulty));
	Map::COLUMNS_MAP = 5 * Map::difficulty + rand() % ((5 * Map::difficulty * 2) - (5 * Map::difficulty));

	Map::map = new cell*[Map::ROWS_MAP];

	for (int i = 0; i < Map::ROWS_MAP; i++) {
		Map::map[i] = new cell[Map::COLUMNS_MAP];
	}

	for (int i = 0; i < Map::ROWS_MAP; i++) {
		for (int j = 0; j < Map::COLUMNS_MAP; j++) {
			Map::map[i][j].hasCoin = false;
			Map::map[i][j].isPlayer = false;
			Map::map[i][j].symbolToShow = '.';
			Map::map[i][j].NUM_COLUMN = j;
			Map::map[i][j].NUM_ROW = i;
		}
	}
}

void Map::Modify(int ROW, int COL, char value) {
	Map::map[ROW][COL].symbolToShow = value;
	if (value == '$')
		Map::map[ROW][COL].hasCoin = true;
	else
		Map::map[ROW][COL].hasCoin = false;
}

void Map::PrintMap() {
	for (int i = 0; i < Map::ROWS_MAP; i++) {
		for (int j = 0; j < Map::COLUMNS_MAP; j++) {
			std::cout << Map::map[i][j].symbolToShow;
		}
		std::cout << std::endl;
	}
}

Map::~Map()
{
}
