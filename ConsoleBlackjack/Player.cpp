#include "Player.h"

Player::Player(double startingCash) : cash(startingCash) {}

double Player::getCash() {
	return cash;
}

void Player::setCash(double cash) {
	this->cash = cash;
}
