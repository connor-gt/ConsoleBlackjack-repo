#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include "Deck.h"

/**
* Create a standard deck of 52 cards.
*/
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

/**
* Shuffle the deck in place using mt19937 and a random seed value.
*/
void Deck::shuffle() {
	auto rng = std::mt19937(time(nullptr)); // Initialize with a random seed value
	std::ranges::shuffle(cards, rng);
}

/**
* Deal a card from the top of the deck.
* 
* @return The card that was dealt from the top of the deck. If no cards remain, empty optional<Card> is returned.
*/
std::optional<Card> Deck::deal() {
	if (cards.empty()) {
		return {};
	}

	Card card = cards.back();
	cards.pop_back();
	return card;
}

/**
* Get a copy of this deck's current cards exactly as they are.
* 
* @return A vector copy of the cards.
*/
std::vector<Card> Deck::getCards() {
	std::vector<Card> copy = cards;
	return copy;
}
