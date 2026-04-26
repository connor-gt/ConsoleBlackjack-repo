#pragma once

#include <vector>
#include "Card.h"

class Deck {
public:
	Deck();
	void shuffle();
	Card deal();

private:
	std::vector<Card> cards;
	int index; // For keeping track of the deal position within the deck
};
