#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "Player.hh"

Player::Player(int &posX, int &posY, int &puntos) {
	x = posX;
	y = posY;
	puntuacion = puntos;
}

void Player::playerinicial(int posX, int posY) {

	x = (rand() % posX);
	y = (rand() % posY);
}

void Player::playeractualiza(Key K) {
	
}







