#pragma once

#include <vector>
#include "Card.h"

class Hand {
public:
	Hand();

	/**
	* Evaluate this hand's current value. Ace interactions are taken into account, where Aces have a value of 11 unless
	* the hand value exceeds 21, where the Ace value is reduced to 1.
	*
	* @return The value of the hand as an int.
	*/
	int evaluate();

	/**
	* Render the current cards in this hand. The cards are rendered horizontally on the same line.
	*/
	void render();

	/**
	* Add a card to this hand.
	*
	* @param card The card to add to the hand.
	*/
	void addCard(Card card);

	/**
	* Hide or unhide a card at a certain index (starting at 0). If the index is out of range, nothing happens.
	*
	* @param index The card's index that should be hidden.
	* @param hide Whether or not the card should be hidden (its rank and suit shown or replaced with X's if hidden).
	*/
	void hideCard(int index, bool hide);

	/**
	* Empty this hand by clearing the cards.
	*/
	void clear();

private:
	std::vector<Card> cards;

	/**
	* Check if this hand currently has an ace.
	*
	* @return True if the hand contains an ace, false if otherwise.
	*/
	bool hasAce();
};
