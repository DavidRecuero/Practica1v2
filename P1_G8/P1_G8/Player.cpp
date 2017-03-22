#include "Player.h"
#include "stdlib.h"

Player::Player(Map mapa, int spawnrange) {
	do {
		x = (mapa.sizex / 2) + rand() % mapa.sizex / spawnrange - mapa.sizex / 2 * spawnrange;
		y = (mapa.sizey / 2) + rand() % mapa.sizey / spawnrange - mapa.sizey / 2 * spawnrange;
	} while (mapa.map[x][y] != '$');
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
			x--;	break;
		case 'd':
		case 'D':
			x++;	break;
		case 'w':
		case 'W':
			y++;	break;
		case 's':
		case 'S':
			y--;	break;
		}
		mapa.cellModify(x, y, '@');
	}

}