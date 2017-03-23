#include "CoinManager.h"
#include "Map.h"
#include <stdlib.h>
#include "Player.h"


CoinManager::CoinManager(Map mapa) {

	coinnum = int(mapa.sizex*mapa.sizey * float(rand() % 100) / 1000.f + 0.03f);
	coinsetter(mapa);
		
}

void CoinManager::coinsetter(Map mapa) {

	for (int c = 0; c < coinnum; c++) {
		int x;
		int y;
		do {
			x = rand() % mapa.sizex;
			y = rand() % mapa.sizey;

		} while (mapa.map[x][y] != '.');
		mapa.cellModify(x, y, '$');
	}
}


	void CoinManager::scoreCounter(Player jugador,int score,Map mapa) {

		if (mapa.map[jugador.x][jugador.y] == '$') {
			score++;
			coinnum--;
		}

		if (coinnum == 0) {
			coinnum = mapa.sizex*mapa.sizey * int(float(rand() % 100) / 1000.f + 0.03f);
			coinsetter(mapa);
		}
	}


