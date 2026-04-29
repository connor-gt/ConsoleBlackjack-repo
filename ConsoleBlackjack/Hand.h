#pragma once

#include <vector>
#include "Card.h"

class Hand {
public:
	int evaluate();
	void render();
	void hit(Card card);

private:
	std::vector<Card> cards;
};
