#pragma once
#include "Map.h"
#include "Player.h"

class Player;
class Map;

class CoinManager {
private:
	Map &map;
	Player &jugador;
public:
	int coinnum;
		

	CoinManager(Map &mapa, Player &jugadore);


	void coinsetter();
	
	void scoreCounter();

};