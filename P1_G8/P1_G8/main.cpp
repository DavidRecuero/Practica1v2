
#include "Input.h"
#include "Map.h"
#include "CoinManager.h"
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>





int main(void) {

	srand(time(nullptr));

	int difficulty;
	int scoreToWin;

	/*
	do { 
		std::cout << "Select difficulty |1, 2, 3|" << std::endl;
		std::cin >> difficulty;
	} while(difficulty < 1 || difficulty > 3);*/
	
	
	Map mapa1(2);

	CoinManager manejador(mapa1);

	Player senyor(mapa1, 1);

	mapa1.printer();

	/*std::cout << manejador.coinnum << std::endl;
	std::cout << mapa1.sizex*mapa1.sizey << std::endl;
	*/

	for (int i = 0; i < 2000; i++) {
		senyor.movement(mapa1);
		mapa1.printer();
	};

}