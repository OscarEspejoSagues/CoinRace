#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "CoinManager.hh"

CoinManager::CoinManager(int &rows, int &colus) {
	filasMapa = rows;
	columnasMapa = colus;
}

int CoinManager::coininmap(apuntCoins **total) const {
	*total = coinData;
	return cantidaddemonedas;
}

int CoinManager::monedas(int rows,int columns) {
	return (rand() % (rows*columns / 10)) + rows*columns*0.03;
}

void CoinManager::coinGenerator(int rows, int columns) {
	
	cantidaddemonedas = monedas(rows, columns);
	coinData = static_cast<apuntCoins*>(malloc(cantidaddemonedas * sizeof(apuntCoins)));
	int randX, randY;
	bool repeated;
	for (int i = 0; i < cantidaddemonedas; i++) {
		do {
			repeated = false;
			randX = rand() % rows;
			randY = rand() % columns;
			for (int j = 0; j < i && !repeated; j++) {
				if (coinData[j].posX == randX && coinData[j].posY == randY) {
					repeated = true;
				}
			}
		} while (repeated);
		coinData[i].posX = randX;
		coinData[i].posY = randY;
	}
};

void CoinManager::removeCoin(int &posX, int &posY) {
	int help = -1;
}

