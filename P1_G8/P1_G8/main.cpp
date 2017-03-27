
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
	int score = 0;
	int temps = 1;

	
	do {
		std::cout << "    ---------------" << std::endl;
		std::cout << "    || COIN RACE ||" << std::endl;
		std::cout << "    ---------------" << std::endl << std::endl;

		std::cout << "Select difficulty |1, 2, 3|" << std::endl;
		std::cin >> difficulty;

	} while(difficulty < 1 || difficulty > 3);
	
	
	Map mapa1(2);

	CoinManager manejador(mapa1);

	Player senyor(mapa1, difficulty);

	mapa1.printer();

	/*std::cout << manejador.coinnum << std::endl;
	std::cout << mapa1.sizex*mapa1.sizey << std::endl;
	*/

	std::cout << "    ---------------" << std::endl;
	std::cout << "    || COIN RACE ||" << std::endl;
	std::cout << "    ---------------" << std::endl << std::endl;
	std::cout << "    ||W - up  ||S - down ||" << std::endl;
	std::cout << "    ||A - left||D - right||" << std::endl;

	senyor.movement(mapa1);
	manejador.scoreCounter(senyor, score, mapa1);
	mapa1.printer();

	while(score < scoreToWin) {
		//if (keypressed) {
			std::cout << "    ---------------" << std::endl;
			std::cout << "    || COIN RACE ||" << std::endl;
			std::cout << "    ---------------" << std::endl << std::endl;
			std::cout << "    ||W - up  ||S - down ||" << std::endl;
			std::cout << "    ||A - left||D - right||" << std::endl;

			senyor.movement(mapa1);
			manejador.scoreCounter(senyor, score, mapa1);
			mapa1.printer();

			std::cout << score << "/" << scoreToWin << std::endl;
		//}
	};

	std::cout << "Congrats!, you have taken " << temps;

}