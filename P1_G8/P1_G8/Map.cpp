#include "Map.h"
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




