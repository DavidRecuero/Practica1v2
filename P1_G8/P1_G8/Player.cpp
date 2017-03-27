#include "Player.h"
#include "stdlib.h"

Player::Player(Map mapa) {
	do {
		x = rand() % mapa.sizex;
		y = rand() % mapa.sizey;
	} while (mapa.map[x][y] == '$');


	mapa.cellModify(x, y, '@');

}
void Player::movement(Map mapa) {

	char entrada;
	if (_kbhit()) {
		entrada = _getch();
		mapa.cellModify(x, y, '.');
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
		}
		mapa.cellModify(x, y, '@');
	}

}