#pragma once

#include "Map.h"
#include "CoinManager.h"

class CoinManager;
class Map;

class Player {

public:

	Map& map;
	CoinManager &coinmanager;

	int x, y;

	int puntuacio;

	Player(Map &mapa, CoinManager &manejador);

	bool  movement(Map &mapa);

	void scoreadd();

	void Player::scoreCounter(Map &mapa, CoinManager &manejador, int coinnum);
};