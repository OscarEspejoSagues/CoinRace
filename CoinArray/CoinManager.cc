#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "CoinManager.hh"

int CoinManager::filasMapa(int filasMapa) {
	return filasMapa;
}

int CoinManager::columnasMapa(int columnasMapa) {
	return columnasMapa;
}

CoinManager::CoinManager(int &rows, int &colus) {            //Constructor de la clase coinManager
	filasMapa(rows);
	columnasMapa(colus);
}

int CoinManager::coininmap(const apuntCoins **total) const {      //Ponemos todas las monedas en el mapa
	*total = coinData;
	return cantidaddemonedas;
}

int CoinManager::monedas(int rows,int columns,int diff) {			//Generamos el numero de monedas
	int maximo = rows*columns*0.13;
	int minimo = rows*columns*0.03;
	return (rand() % (maximo-minimo)) + minimo;
}

void CoinManager::coinGenerator(int rows, int columns,int diff) {    //Reposicionamos las monedas de manera que no se repita la posicion de ninguna de ellas
	
	cantidaddemonedas = monedas(filasMapa(rows), columnasMapa(columns),diff);
	coinData = new coin[cantidaddemonedas]; 
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

void CoinManager::removeCoin(int &posX, int &posY,int diff,int rows,int cols) {  //Metodo para eliminar las monedas una vez acabado
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
		if (cantidaddemonedas <= 0) {
			delete[] coinData;
			coinGenerator(filasMapa(rows), columnasMapa(cols), diff);
		}
	}
}

