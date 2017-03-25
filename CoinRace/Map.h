#pragma once
class Map
{
private:
	char** map;
	int difficulty, ROWS_MAP, COLUMNS_MAP;

public:

	Map(int dificultad);

	void Modify(int ROW, int COL, char value);

	void PrintMap();

	int getDifficulty();
	
	int getMapRows();

	int getMapCols();

	char getPos(int ROW, int COL);

	~Map();
};

