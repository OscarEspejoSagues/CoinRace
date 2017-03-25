#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include "Map.hh"


Map::Map(int &diff, int &filas, int &columnas) {                           //constructor del mapa
	filas = ((rand() % (10 * diff - 5 * diff)) + 5 * diff);
	columnas = ((rand() % (10 * diff - 5 * diff)) + 5 * diff);
}

void Map::mapGenerator(int &filas, int &columnas) {                       //Aqui generamos el mapa
	md = new char*[filas];												  //tanto las columnas como las filas y las inicializamos en '.'
		for (int i = 0; i < filas; i++) {
			md[i] = new char[columnas];
			for (int j = 0; j < columnas; j++) {
				md[i][j] = '.';
			}
		}
	}

void Map::printField(int &filas, int &columnas) {						//Imprimimos el mapa 
		char print;
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				print = md[i][j];
				std::cout << print;
			}
			std::cout << std::endl;
		}
	}

void Map::changeSymbol(int row, int col, char sym) {                     //Cambio del simbolo que muestra
		md[row][col] = sym;
	}




