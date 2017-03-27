#include "CoinManager.h"
#include "Map.h"
#include <stdlib.h>
#include "Player.h"


CoinManager::CoinManager(Map &mapa) : map (mapa){

	coinnum = int(mapa.sizex*mapa.sizey * float(rand() % 13 + 3) / 100.f);
	coinsetter();
		
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



