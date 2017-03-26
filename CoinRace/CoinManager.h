#pragma once
#include "Map.h"

class CoinManager
{

private:

	int coins, coinsFinal;

public:

	Map *myMap;
	
	CoinManager(Map &m); //Funcion que rellena el mapa de monedas, calcula el numero de monedas maximo de la partida

	int getCoinsFinal(); //Funcion que devuelve el valor de la variable coinsFinal
	
	void Manage();//Funcion que cuenta el numero de monedas que hay en el mapa y si es <= 0 lo vuelve a rellenar
	
	~CoinManager();
};

