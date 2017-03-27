#include "Map.h"
#include "Input.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>


Map::Map(int difficulty)
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

	std::cout << "        ---------------" << std::endl;
	std::cout << "        || COIN RACE ||" << std::endl;
	std::cout << "        ---------------" << std::endl << std::endl;
	std::cout << "    ||W - up  ||S - down ||" << std::endl;
	std::cout << "    ||A - left||D - right||" << std::endl << std::endl << std::endl;

	for (int c = 0; c < sizex; c++) {
		std::cout << "   ";
		for (int i = 0; i < sizey; i++) {
			std::cout << " " << map[c][i] << " ";
		}
		std::cout << std::endl;
	}

}

Map::~Map() {

	for (int c = 0; c < sizex; c++) {
		delete[] map[c];
		map[c] = nullptr;
	}
	delete[] map;
	map = nullptr;

}




