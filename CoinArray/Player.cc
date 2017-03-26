#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include "Player.hh"

Player::Player(int &posX, int &posY, int &puntos) {  //Constructor de la clase Player
	x = posX;
	y = posY;
	puntuacion = puntos;
}

void Player::playerinicial(int posX, int posY) {     //Posicion Random del Player
	x = (rand() % posX);
	y = (rand() % posY);
}

int Player::recojerCoin() {                        //Devolvemos el valor de las monedas que recoje el player
	return puntuacion;
}

void Player::movimientoplayer(Key key) {           //Switch que permite el movimiento del player

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










