#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Map.hh"
#include "Player.hh"
#include "CoinManager.hh"
#include<Windows.h>



using namespace std;

int menu() {

	int diff;

	system("color 8B");
	std::cout << "     //////////////////////////////     " << std::endl;
	std::cout << "               COIN RACE           " << std::endl;
	std::cout << "     //////////////////////////////     " << std::endl;
	std::cout << endl;

	std::cout << "Selecciona una de las 3 dificultades" << std::endl;
	std::cout << endl;
	std::cout << "     Easy == 1     " << std::endl;
	std::cout << "     Normal == 2   " << std::endl;
	std::cout << "     Hard == 3     " << std::endl;
	std::cout << endl;

	std::cin >> diff;

	return diff;

}

void updateMap(int &row, int &col, HANDLE hConsole, Map map, const Player &p, const CoinManager & coin_manager, int coin_target) {
	system("cls");
	apuntCoins *coin_data;
	int cantidaddemonedas;
	cantidaddemonedas = coin_manager.coininmap(&coin_data);
	for (int i = 0; i < cantidaddemonedas; ++i) {
		map.changeSymbol(coin_data[i].posX, coin_data[i].posY, '$');
	}
	map.printField(row, col);
	map.changeSymbol(p.x, p.y, p.pj);
	std::cout << std::endl << "Score: ";
	std::cout << p.puntuacion;
}

bool checkNextPosition(int &rows, int &columns, const Map &map, const Player &jugador, const Key &key) {
	switch (key) {
	case Key::A:
		return jugador.y > 0;
	case Key::W:
		return jugador.x > 0;
	case Key::S:
		return jugador.x <  rows - 1;
	case Key::D:
		return jugador.y < columns - 1;
	}
}

int main() {
	srand(time(nullptr));

	int diff = menu();
	int row;
	int col;
	int puntuacion = 0;

	Map mapa = Map(diff, row, col);
	Player jugador = Player(row, col, puntuacion);
	CoinManager coins = CoinManager(row, col);

	int totalCoins = coins.monedas(row, col);
	mapa.mapGenerator(row, col);
	jugador.playerinicial(row, col);
	coins.coinGenerator(row, col);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	mapa.changeSymbol(jugador.x, jugador.y, '@');
	updateMap(row, col, hConsole, mapa, jugador, coins, totalCoins);
	

	bool tecla = true;

	while (jugador.puntuacion < totalCoins) {
		
		Key key = getKey();
		if (key == Key::ESC) {
			return 0;
		}
		else if (key == Key::NONE) {
			continue;
		}
		else {
			mapa.changeSymbol(jugador.x, jugador.y, '.');
			if (checkNextPosition(row,col,mapa, jugador, key)) {
				jugador.movimientoplayer(key);
			}
		}
		mapa.changeSymbol(jugador.x, jugador.y, '@');
		updateMap(row,col,hConsole, mapa, jugador, coins, totalCoins);
		
	}
}