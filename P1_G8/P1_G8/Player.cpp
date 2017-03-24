#include "Player.h"
#include "stdlib.h"

Player::Player(Map mapa, int spawnrange) {
	do {
		x = (mapa.sizex / 2) + rand() % mapa.sizex / spawnrange - mapa.sizex / 2 * spawnrange;
		y = (mapa.sizey / 2) + rand() % mapa.sizey / spawnrange - mapa.sizey / 2 * spawnrange;
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