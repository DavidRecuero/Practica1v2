#pragma once
#include "Map.h"
#include "Player.h"

class CoinManager {

public:
	int coinnum;
		

	CoinManager(Map mapa);


	void coinsetter(Map);
	
	void scoreCounter(Player jugador, int score,Map mapa);

};