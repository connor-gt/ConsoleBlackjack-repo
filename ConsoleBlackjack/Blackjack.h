#pragma once

#include "Player.h"

class Blackjack {
public:
	void start(Player& player);

private:
	bool askPlayAgain(Player& player);
	double getBet(Player& player);
};
