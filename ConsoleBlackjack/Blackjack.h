#pragma once

#include "Player.h"
#include "Deck.h"

class Blackjack {
public:
	void start(Player& player); // Could handle playing the entire session
	void playRound(Player& player, Deck& deck); // Add dealer as parameter when I make it

private:
	bool askPlayAgain();
};

