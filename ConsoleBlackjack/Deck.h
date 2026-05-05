#pragma once

#include <vector>
#include <optional>
#include "Card.h"

class Deck {
public:
	/**
	* Create a standard deck of 52 cards.
	*/
	Deck();

	/**
	* Shuffle the deck in place using mt19937 and a random seed value.
	*/
	void shuffle();

	/**
	* Deal a card from the top of the deck.
	*
	* @return The card that was dealt from the top of the deck. If no cards remain, empty optional<Card> is returned.
	*/
	std::optional<Card> deal();

	/**
	* Get a copy of this deck's current cards exactly as they are.
	*
	* @return A vector copy of the cards.
	*/
	std::vector<Card> getCards();

private:
	std::vector<Card> cards;
};
