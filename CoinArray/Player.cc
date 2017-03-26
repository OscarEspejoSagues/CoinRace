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

int Player::recojerCoin() {
	return puntuacion;
}

void Player::movimientoplayer(Key key) {

	switch (key) {
	case Key::W:
		x--;
		break;
	case Key::A:
		y--;
		break;
	case Key::S:
		x++;
		break;
	case Key::D:
		y++;
		break;
	}

}










