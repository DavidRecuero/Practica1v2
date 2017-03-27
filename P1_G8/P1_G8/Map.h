#pragma once

#include "Input.h"
#include "Player.h"


class Player;

class Map {

public:

	
	char **map; // doble punter que apunta la matriu

	int sizex; // llargada del mapa.

	int sizey; // alçada del mapa

	Map(int difficulty);

	void cellModify(const int &line, const int &row, const char &newelement);


	void printer();




};





