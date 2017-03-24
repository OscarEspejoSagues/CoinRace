#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "Player.hh"

Player::Player(int posX, int posY) {
	x = posX;
	y = posY;
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}

void Player::SetPuntuacion(int puntos) {
	puntuacion = puntos;
}

int Player::retpuntuacio() {
	return puntuacion;
}
