#pragma once

#include "Map.h"
#include "CoinManager.h"

class CoinManager;
class Map;

class Player {

private:

	Map& map; // referencia a Map
	CoinManager &coinmanager; // referencia a CoinManager

public:
	int x, y; // posició x i y del jugador

	int puntuacio; // numero de monedes recollides pel jugador

	Player(Map &mapa, CoinManager &manejador); // constructor


	bool  movement();



	void scoreCounter();
};