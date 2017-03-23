
#include "Input.h"
#include "Map.h"
#include "CoinManager.h"
#include "Player.h"
#include <time.h>
#include <stdlib.h>





int main(void) {

	srand(time(nullptr));

	int difficulty;
	int scoreToWin;

	
	Map mapa1(2);

	CoinManager manejador(mapa1);

	mapa1.printer();





}