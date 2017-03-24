#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "Map.hh"

using namespace std;

Map::Map(int &diff) {
	row = ((rand() % (10 * diff - 5 * diff)) + 5 * diff);
	col = ((rand() % (10 * diff - 5 * diff)) + 5 * diff);
	mapGenerator();
	printField();
}

void Map::mapGenerator() {
		md = new char*[row];
		for (int i = 0; i < row; i++) {
			md[i] = new char[col];
			for (int j = 0; j < col; j++) {
				md[i][j] = '.';
			}
		}
	}

void Map::printField() {
		char print;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				print = md[i][j];
				std::cout << print;
			}
			std::cout << std::endl;
		}
	}

void Map::changeSymbol(int row, int col, char sym) {
		md[row][col] = sym;
	}




