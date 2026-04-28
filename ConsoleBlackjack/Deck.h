#pragma once

#include <vector>
#include <optional>
#include "Card.h"

class Deck {
public:
	Deck();
	void shuffle();
	std::optional<Card> deal();
	std::vector<Card> createCopy();

private:
	std::vector<Card> cards;
};
