#pragma once

#include <vector>
#include "Card.h"

class Hand {
public:
	Hand();
	int evaluate();
	void render();
	void hit(Card card);

private:
	std::vector<Card> cards;
	bool hasAce();
};
