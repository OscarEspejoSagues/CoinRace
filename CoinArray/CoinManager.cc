#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "CoinManager.hh"

class CoinManager {
public:
	char symbolCoin;
	int numberofCoins;
	int numcoinsrecogidas;

	void coinGenerator(int rows, int columns) {
		int minimo = (rows*columns)*0.03;
		int max = (rows*columns)*0.13;
		numberofCoins = (rand() % (max - minimo)) + minimo;
	}

	Map &mapa;
	CoinManager::CoinManager(Map &map) : mapa(map) {
		mapa.changeSymbol = map.changeSymbol;
	};

	void coininmap(int rows, int columns) {

		int monedaspuestas = 0;
		bool hascoin;
		int posX;
		int posY;

		int minimo = (rows*columns)*0.03;
		int max = (rows*columns)*0.13;
		numberofCoins = (rand() % (max - minimo)) + minimo;

		do
		{
			posX = rand() % ;
			posY = rand()...;
		pickCoord:
			if (mapa[posX][posY] == ’$’ || mapa[posX][posY] == ’@’) {
				posX = rand()...;
				posY = rand()...;
				goto pickCoord;
			}
			else {
				monedaspuestas++;
				mapa[posX][posY] = ’$’;
			}

		} while (monedaspuestas < numberofCoins);
	}
};
