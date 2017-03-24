#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "Map.hh"
#include "Player.hh"
#include "CoinManager.hh"

using namespace std;

int menu() {

	int diff;
	std::cout << "//////////////////////////////" << std::endl;
	std::cout << "          COIN RACE           " << std::endl;
	std::cout << "//////////////////////////////" << std::endl;
	std::cout << "Selecciona una de las 3 dificultades" << std::endl;
	std::cout << "Easy == 1" << std::endl;
	std::cout << "Normal == 2" << std::endl;
	std::cout << "Hard == 3" << std::endl;

	std::cin >> diff;
	return diff;

}

void main() {
	menu();

}
