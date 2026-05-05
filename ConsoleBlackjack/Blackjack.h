#pragma once

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Blackjack {
public:
	void start(Player& player);
	void playRound(Player& player, Dealer& dealer, Deck& deck);

private:
	bool askPlayAgain();
};

