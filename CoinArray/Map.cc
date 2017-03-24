#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "Map.hh"


Map::Map(int &diff, int &filas, int &columnas) {
	filas = ((rand() % (10 * diff - 5 * diff)) + 5 * diff);
	columnas = ((rand() % (10 * diff - 5 * diff)) + 5 * diff);
}

void Map::mapGenerator(int &filas, int &columnas) {
		md = new char*[filas];
		for (int i = 0; i < filas; i++) {
			md[i] = new char[columnas];
			for (int j = 0; j < columnas; j++) {
				md[i][j] = '.';
			}
		}
	}

void Map::printField(int &filas, int &columnas) {
		char print;
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				print = md[i][j];
				std::cout << print;
			}
			std::cout << std::endl;
		}
	}

void Map::changeSymbol(int row, int col, char sym) {
		md[row][col] = sym;
	}




