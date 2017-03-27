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
			y--;	break;
		case 'd':
		case 'D':
			y++;	break;
		case 'w':
		case 'W':
			x--;	break;
		case 's':
		case 'S':
			x++;	break;

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

void Player::scoreCounter