#pragma once
#include "Map.h"
#include "CoinManager.h"
#include "Input.hh"
class Player
{

private:
	
	int playerCols, playerRows, score;

public:
	
	Map *myMap;
	
	CoinManager *myManager;
	
	Player(Map &m, CoinManager &p); //Funcion que situa al jugador en una posicion aleatoria que no tenga moneda, guarda la posicion del jugador y pone el score a 0
	
	void Move(Input::Key key); // Funcion que recibe una tecla y mueve al jugador en la posicion dada por la tecla. Si el jugador coge una moneda, se actualiza el score

	int getScore(); //Funcion que devuelve el valor de la variable score
	
	~Player();
};

