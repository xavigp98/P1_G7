#include "Map.h"
#include <iostream>
#include <cstdlib>



Map::Map()
{
	std::cout << "Escoge nivel de dificultad:" << std::endl << "Pulsa 1 para nivel facil" << std::endl << "Pulsa 2 para nivel normal" << std::endl << "Pulsa 3 para nivel dificil" << std::endl;

	std::cin >>difficulty;

	ROWS_MAP = 5 * difficulty + rand() % ((5 * difficulty * 2) - (5 * difficulty));
	COLUMNS_MAP = 5 *difficulty + rand() % ((5 * difficulty * 2) - (5 * difficulty));

	map = new char*[Map::ROWS_MAP];

	for (int i = 0; i < ROWS_MAP; i++) {
		map[i] = new char[COLUMNS_MAP];
	}

	for (int i = 0; i < ROWS_MAP; i++) {
		for (int j = 0; j < COLUMNS_MAP; j++) {
			map[i][j] = '.';
		}
	}
}

void Map::Modify(int ROW, int COL, char value) {
	map[ROW][COL] = value;
}

void Map::PrintMap() {
	system("CLS");
	for (int i = 0; i < ROWS_MAP; i++) {
		for (int j = 0; j < COLUMNS_MAP; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

Map::~Map()
{
	for (int i = 0; i < ROWS_MAP; i++)
		delete[] map[i];
	delete[] map;
}
