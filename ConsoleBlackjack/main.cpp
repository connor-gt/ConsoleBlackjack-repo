#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"

int main()
{
	Deck deck{};

	std::vector<Card> unshuffled = deck.createCopy();
	for (const Card& card : unshuffled) {
		Card::render(card);
	}

	deck.shuffle();

	std::vector<Card> shuffled = deck.createCopy();
	for (const Card& card : shuffled) {
		Card::render(card);
	}

	return 0;
}
