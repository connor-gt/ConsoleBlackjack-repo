#pragma once

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Round {
public:
	Round(Player& player, Dealer& dealer, Deck& deck);

private:
	void initialize();
	std::string bettingPhase();
	void endPhase();
	Player player;
	Dealer dealer;
	Deck deck;
};
