#include <iostream>
#include <vector>
#include <optional>
#include "Card.h"
#include "Deck.h"

int main()
{
	Deck deck{};

	for (int i = 0; i < 150; i++) {
		std::optional<Card> dealtCard = deck.deal();

		if (dealtCard) {
			Card::render(dealtCard.value());
		}
	}

	/*
	std::vector<Card> unshuffled = deck.createCopy();
	for (const Card& card : unshuffled) {
		Card::render(card);
	}
	*/
	return 0;
}
