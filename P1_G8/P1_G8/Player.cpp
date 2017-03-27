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
			if (y < 0) {
			}
			else { y--;}	break;

		case 'd':
		case 'D':
			if (y > map.sizey) {
			}
			else { y++; }	break;

		case 'w':
		case 'W':
			if (x < 0) {
			}
			else { x--; }	break;

		case 's':
		case 'S':
			if (x > map.sizex) {
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

	if (map.map[x][y] == '$') {
		puntuacio++;
		coinmanager.coinnum--;
	}

	if (coinmanager.coinnum == 0) {
		coinmanager.coinnum = int(mapa.sizex*mapa.sizey * float(rand() % 13 + 3) / 100.f);
		coinmanager.coinsetter();
	}

}