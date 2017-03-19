#pragma once
class Map
{
public:

	int difficulty, ROWS_MAP,COLUMNS_MAP;

	struct cell {
		bool hasCoin;
		char symbolToShow;
		int NUM_COLUMN;
		int NUM_ROW;
	};

	cell** map;

	Map();

	~Map();
};

