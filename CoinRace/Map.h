#pragma once
class Map
{
public:

	static int difficulty, ROWS_MAP,COLUMNS_MAP;

	struct cell {
		bool hasCoin;
		bool isPlayer;
		char symbolToShow;
		int NUM_COLUMN;
		int NUM_ROW;
	};

	static cell** map;

	Map();

	void Modify(int ROW, int COL, char value);

	void PrintMap();

	~Map();
};

