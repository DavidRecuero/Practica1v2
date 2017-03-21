#include "objects.h"
#include "Input.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>


Map::Map(const int &difficulty)
{
	sizex = difficulty * (rand() % 6 + 5);
	sizey = difficulty * (rand() % 6 + 5);

	map = new char*[sizex];

	for (int c = 0; c < sizex;c++) {
		map[c] = new char[sizey];
	}

	for (int c = 0; c < sizex;c++) {
		for (int i = 0; i < sizey;i++) {
			map[c][i] = '.';
		}
		
	}

}
void Map::cellModify(const int &line, const int &row, const char &newelement) {

	map[line][row] = newelement;


}

void Map::printer() {

	system("cls");

	for (int c = 0; c < sizex; c++) {
		for (int i = 0; i < sizey; i++) {
			std::cout << map[c][i];
		}
		std::cout << std::endl;
	}


}

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

Coinmanager::Coinmanager(int coinproportion, Map mapa) {

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
