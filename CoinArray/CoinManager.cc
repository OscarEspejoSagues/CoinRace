#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "CoinManager.hh"

CoinManager::CoinManager(int &rows, int &colus) {            //Constructor de la clase coinManager
	filasMapa = rows;
	columnasMapa = colus;
}

int CoinManager::coininmap(apuntCoins **total) const {      //Ponemos todas las monedas en el mapa
	*total = coinData;
	return cantidaddemonedas;
}

int CoinManager::monedas(int rows,int columns) {			//Generamos el numero de monedas
	return (rand() % (rows*columns / 10)) + rows*columns*0.03;
}

void CoinManager::coinGenerator(int rows, int columns) {    //Reposicionamos las monedas de manera que no se repita la posicion de ninguna de ellas
	
	cantidaddemonedas = monedas(rows, columns);
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

void CoinManager::removeCoin(int &posX, int &posY) {  //Metodo para eliminar las monedas una vez acabado
	int help = -1;
}

