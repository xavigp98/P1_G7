#pragma once
class Map
{
public:

	int difficulty, ROWS_MAP,COLUMNS_MAP;

	char** map;

	Map();

	void Modify(int ROW, int COL, char value);

	void PrintMap();

	~Map();
};

