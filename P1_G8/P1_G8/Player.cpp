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
			if (y == 0) {
				y == map.sizey - 1;
			}
			else { y--;}	break;

		case 'd':
		case 'D':
			if (y == map.sizey -1) {
				y == 0;
			}
			else { y++; }	break;

		case 'w':
		case 'W':
			if (x == 0) {
				x == map.sizey - 1;
			}
			else { x--; }	break;

		case 's':
		case 'S':
			if (x == map.sizex - 1 ) {
				x == 0;
			}
			else { x++; }	break;

			return true;
		}
	}
	else {
		return false;
	}
		
	

}



void Player::scoreCounter() {

	if (map.map[x][y] != '.') {
		puntuacio++;
		coinmanager.coinnum--;
	}

	if (coinmanager.coinnum == 0) {
		coinmanager.coinnum = map.sizex*map.sizey * int(float(rand() % 100) / 1000.f + 0.03f);
		coinmanager.coinsetter();
	}

}