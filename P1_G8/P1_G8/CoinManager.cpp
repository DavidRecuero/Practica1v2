#include "CoinManager.h"
#include "Map.h"
#include <stdlib.h>


CoinManager::CoinManager(int coinproportion, Map mapa) {

	coinnum = mapa.sizex*mapa.sizey / coinproportion;

	for (int c = 0; c < coinnum; c++) {
		int x;
		int y;
		do {
			x = rand() % mapa.sizex;
			y = rand() % mapa.sizey;

		} while (mapa.map[x][y] != '.');
		mapa.map[x][y];
	}
	
}

void CoinManager::coinputter(Map mapa){

	
}