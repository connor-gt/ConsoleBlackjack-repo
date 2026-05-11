#pragma once

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Round {
public:
	Round(Player& player, Dealer& dealer, Deck& deck, double bet);

private:
	void initialize();
	std::string bettingPhase();
	Player& player;
	Dealer& dealer;
	Deck& deck;
	double bet;
};
