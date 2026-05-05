#pragma once

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Round {
public:
	void play(Player& player, Dealer& dealer, Deck& deck);

private:
	void initialize(Player& player, Dealer& dealer, Deck& deck);
	void bettingPhase(Player& player, Deck& deck);
	void endPhase();
};

