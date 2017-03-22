#pragma once

#include "Map.h"

class Player {

public:

	int x, y;

	int puntuacio;

	Player(Map mapa, int spawnrange);

	void  movement(Map mapa);


};