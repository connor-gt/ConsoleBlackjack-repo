#pragma once

#include <vector>
#include "Card.h"

class Hand {
public:
	Hand();
	int evaluate();
	void render();
	void addCard(Card card);
	void hideCard(int index, bool hide);
	void clear();

private:
	std::vector<Card> cards;
	bool hasAce();
};
