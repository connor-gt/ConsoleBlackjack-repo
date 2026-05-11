#pragma once

#include "Player.h"

class Blackjack {
public:
	void start(Player& player);

private:
	bool askPlayAgain();
	double getBet(Player& player);
};
