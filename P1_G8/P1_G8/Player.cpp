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
bool Player::movement(Map &mapa) {

	char entrada;
	if (_kbhit()) {
		entrada = _getch();
		map.cellModify(x, y, '.');
		switch (entrada) {

		case 'a':
		case 'A':
			if (y == 0) {
				y == mapa.sizey;
			}
			else { y--;}	break;

		case 'd':
		case 'D':
			if (y == mapa.sizey) {
				y == 0;
			}
			else { y++; }	break;

		case 'w':
		case 'W':
			if (x == 0) {
				x == mapa.sizey;
			}
			else { x--; }	break;

		case 's':
		case 'S':
			if (x == mapa.sizex) {
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

void Player::scoreadd() {

	puntuacio++;
}

void Player::scoreCounter(Map &mapa, CoinManager &manejador, int coinnum) {

	if (mapa.map[jugador.x][jugador.y] == '$') {
		jugador.puntuacio++;
		coinnum--;
	}

	if (coinnum == 0) {
		coinnum = mapa.sizex*mapa.sizey * int(float(rand() % 100) / 1000.f + 0.03f);
		manejador.coinsetter();
	}

}