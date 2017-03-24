#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "Map.hh"
#include "Player.hh"



using namespace std;

int menu() {

	int diff;
	std::cout << "//////////////////////////////" << std::endl;
	std::cout << "          COIN RACE           " << std::endl;
	std::cout << "//////////////////////////////" << std::endl;
	std::cout << "Selecciona una de las 3 dificultades" << std::endl;
	std::cout << endl;
	std::cout << "Easy == 1" << std::endl;
	std::cout << "Normal == 2" << std::endl;
	std::cout << "Hard == 3" << std::endl;
	std::cout << endl;

	std::cin >> diff;

	return diff;

}


void main() {
	srand(time(nullptr));

	int diff = menu();
	int row;
	int col;
	int puntuacion = 0;
	Map mapita = Map(diff, row, col);
	Player jugador = Player(row, col, puntuacion);
	mapita.mapGenerator(row, col);
	jugador.playerinicial(row, col);
	mapita.changeSymbol(jugador.x, jugador.y, '@');
	mapita.printField(row, col);

	bool tecla = false;
	while (tecla){
		jugador.playeractualiza(row, col, tecla);
	}


}
