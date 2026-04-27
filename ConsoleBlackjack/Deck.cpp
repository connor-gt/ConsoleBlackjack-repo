#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <optional>
#include "Card.h"
#include "Deck.h"

Deck::Deck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j <= 14; j++) {
			std::string suit;
			switch (i) {
				case 0:
					suit = "C";
					break;
				case 1:
					suit = "D";
					break;
				case 2:
					suit = "H";
					break;
				case 3:
					suit = "S";
					break;
			}

			Card card(j, suit);
			cards.push_back(card);
		}
	}
}

void Deck::shuffle() {
	auto rng = std::mt19937(time(nullptr)); // Initialize with a random seed value
	std::ranges::shuffle(cards, rng);
}

std::optional<Card> Deck::deal() {
	if (cards.empty()) {
		return {};
	}

	Card card = cards.back();
	cards.pop_back();
	return card;
}

std::vector<Card> Deck::createCopy() {
	std::vector<Card> copy = cards;
	return copy;
}
