#include <algorithm>
#include "Hand.h"

/**
* Create an empty hand.
*/
Hand::Hand() {}

/**
* Evaluate this hand's current value. Ace interactions are taken into account, where Aces have a value of 11 unless
* the hand value exceeds 21, where the Ace value is reduced to 1.
* 
* @return The value of the hand as an int.
*/
int Hand::evaluate() {
	int value = 0;

	for (const Card& card : cards) {
		if (card.rank <= 10) {
			value += card.rank;
		}
		else if (card.rank < 14) {
			value += 10;
		}
		else {
			value += 11;
		}
	}

	// Check and account for Ace interactions (Ace being 11 or 1 depending on hand value)
	while (value > 21 && hasAce()) {
		value -= 10;
	}

	return value;
}

/**
* Render the current cards in this hand. The cards are rendered horizontally on the same line.
*/
void Hand::render() {
	Card::render(cards);
}

/**
* Add a card to this hand.
*/
void Hand::addCard(Card card) {
	cards.push_back(card);
}

/**
* Empty this hand by clearing the cards.
*/
void Hand::clear() {
	cards.clear();
}

/**
* Check if this hand currently has an ace.
* 
* @return True if the hand contains an ace, false if otherwise.
*/
bool Hand::hasAce() {
	for (const Card& card : cards) {
		if (card.rank == 14) {
			return true;
		}
	}

	return false;
}
