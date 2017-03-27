#include "Player.h"
#include "stdlib.h"
#include "CoinManager.h"

Player::Player(Map &mapa, CoinManager &manejador) : map (mapa), coinmanager(manejador) {
	
	puntuacio = 0;
	
	do {
		x = rand() % mapa.sizex;
		y = rand() % mapa.sizey;
	} while (mapa.map[x][y] == '$');


	mapa.cellModify(x, y, '@');

}
bool Player::movement() {

	char entrada;
	if (_kbhit()) {
		entrada = _getch();
		map.cellModify(x, y, '.');
		switch (entrada) {

		case 'a':
		case 'A':
			if (y > 0) {
				y--;
			}
			break;

		case 'd':
		case 'D':
			if (y + 1 < map.sizey) {
				y++;
			}
			break;

		case 'w':
		case 'W':
			if (x > 0) {
				x--;
			}
			break;

		case 's':
		case 'S':
			if (x + 1 < map.sizex) {
				x++;
			}
			break;
					
		}
		return true;
	}
	else {
		return false;
	}
		
	

}



void Player::scoreCounter() {

	if (coinmanager.coinnum == 0) {
		coinmanager.coinnum = int(map.sizex*map.sizey * float(rand() % 13 + 3) / 100.f);
		coinmanager.coinsetter();
	}

	if (map.map[x][y] == '$') {
		puntuacio++;
		coinmanager.coinnum--;
	}



}

