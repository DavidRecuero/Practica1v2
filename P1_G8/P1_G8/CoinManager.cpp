#include "CoinManager.h"
#include "Map.h"
#include <stdlib.h>
#include "Player.h"


CoinManager::CoinManager(Map &mapa, Player &jugadore) : map (mapa), jugador(jugadore) {

	coinnum = int(mapa.sizex*mapa.sizey * float(rand() % 13 + 3) / 100.f);
	coinsetter(mapa);
		
}

void CoinManager::coinsetter() {

	for (int c = 0; c < coinnum; c++) {
		int x;
		int y;
		do {
			x = rand() % map.sizex;
			y = rand() % map.sizey;

		} while (map.map[x][y] != '.');
		map.cellModify(x, y, '$');
	}
}


void CoinManager::scoreCounter() {

		if (map.map[jugador.x][jugador.y] == '$') {
			jugador.puntuacio++;
			coinnum--;
		}

		if (coinnum == 0) {
			coinnum = map.sizex*map.sizey * int(float(rand() % 100) / 1000.f + 0.03f);
			coinsetter();
		}
	}


