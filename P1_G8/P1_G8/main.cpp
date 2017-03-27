
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
	int scoreToWin = 10;
	
	int temps = 1;

	
	do {
		std::cout << "    ---------------" << std::endl;
		std::cout << "    || COIN RACE ||" << std::endl;
		std::cout << "    ---------------" << std::endl << std::endl;

		std::cout << "Select difficulty |1, 2, 3|" << std::endl;
		std::cin >> difficulty;

	} while(difficulty < 1 || difficulty > 3);
	
	
	Map mapa1(difficulty);

	CoinManager manejador(mapa1,*senyor);

	

	senyor = new Player(mapa1,manejador);

	mapa1.printer(scoreToWin);

	

	while(senyor*.puntuacio < scoreToWin) {
					
			
			if (senyor*.movement(mapa1, manejador, scoreToWin)) {
				manejador.scoreCounter();

				mapa1.cellModify(senyor*.x, senyor*.y, '@');

				mapa1.printer(scoreToWin);
			}
	};

	std::cout << "Congrats!, you have taken " << temps;

}