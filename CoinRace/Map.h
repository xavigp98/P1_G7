#pragma once
class Map
{
private:
	char** map;
	int difficulty, ROWS_MAP, COLUMNS_MAP;

public:

	Map(int dificultad); //Funcion que crea el mapa en funcion del nivel de dificultad  y lo llena de puntos

	void Modify(int ROW, int COL, char value); //Funcion que recibe un numero de fila, un numero de columna y un char y substituye ese char en la posicion designada del mapa

	void PrintMap(); //Funcion que imprime el mapa por consola

	int getDifficulty(); //Funcion que devuelve el valor de la dificultad
	
	int getMapRows(); //Funcion que devuelve el numero de filas del mapa

	int getMapCols(); //Funcion que devuelve el numero de columnas del mapa

	char getPos(int ROW, int COL); //Funcion que devuelve el valor  de la posicion del mapa que recibe

	~Map();
};

