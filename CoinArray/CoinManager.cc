#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "CoinManager.hh"

CoinManager::CoinManager(int &rows, int &colus) {            //Constructor de la clase coinManager
	filasMapa = rows;
	columnasMapa = colus;
}

int CoinManager::coininmap(const apuntCoins **total) const {      //Ponemos todas las monedas en el mapa
	*total = coinData;
	return cantidaddemonedas;
}

int CoinManager::monedas(int rows,int columns,int diff) {			//Generamos el numero de monedas
	return (rand() % diff * 30 + 1) + diff * 30;
}

void CoinManager::coinGenerator(int rows, int columns,int diff) {    //Reposicionamos las monedas de manera que no se repita la posicion de ninguna de ellas
	
	cantidaddemonedas = monedas(filasMapa, columnasMapa,diff);
	coinData = static_cast<apuntCoins*>(malloc(cantidaddemonedas * sizeof(apuntCoins)));  //Usando malloc, podemos reservar un espacio de memoria sin necessidad de
	int randX, randY;                                                                    //poner un valor en el
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

void CoinManager::removeCoin(int &posX, int &posY,int diff) {  //Metodo para eliminar las monedas una vez acabado
	int pos = -1;
	for (int i = 0; i < cantidaddemonedas && pos == -1; i++) {
		if (coinData[i].posX == posX && coinData[i].posY == posY) {
			pos = i;
		}
	}
	if (pos >= 0 && pos < cantidaddemonedas) {
		for (int i = pos; i < cantidaddemonedas - 1; i++) {
			coinData[i] = coinData[i + 1];
		}
		cantidaddemonedas--;
		if (cantidaddemonedas > 0) {
			coinData = static_cast<apuntCoins*>(realloc(coinData, cantidaddemonedas * sizeof(apuntCoins)));
		}
		else {
			coinGenerator(filasMapa, columnasMapa, diff);
		}
	}
}

