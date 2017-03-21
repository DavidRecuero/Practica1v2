#pragma once


#include "Input.h"

class Map {

public:

	char **map; // doble punter que apunta la matriu

	int sizex; // llargada del mapa.

	int sizey; // alçada del mapa

	Map(const int &difficulty);

	void cellModify(const int &line, const int &row, const char &newelement);


	void printer();



};

class Player {

public:

	int x, y;

	int puntuacio;

	Player(Map mapa, int spawnrange);

	void  movement(Map mapa);


};

class Coinmanager {

public:
	int coinnum;

	const int coinproportion = 10; // proporcio de monedes segons la grandaria del mapa ( 100/3 , 100/13)

	Coinmanager(int coinproportion, Map mapa);



};

