#pragma once
class Map
{
private:
	char** map;

public:

	int difficulty, ROWS_MAP,COLUMNS_MAP;

	Map();

	void Modify(int ROW, int COL, char value);

	void PrintMap();

	char getPos(int ROW, int COL);

	~Map();
};

