#pragma once

#include "Map.h"

class Player {

public:

	int x, y;

	int puntuacio;

	Player(Map mapa);

	void  movement(Map mapa);


};