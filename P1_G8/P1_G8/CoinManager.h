#pragma once
#include "Map.h"
#include "Player.h"

class Player;
class Map;

class CoinManager {
private:
	Map &map;
public:
	int coinnum;
		

	CoinManager(Map &mapa);


	void coinsetter();
	

};