#include <algorithm>
#include "Hand.h"

Hand::Hand() {}

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

void Hand::render() {
	Card::render(cards);
}

void Hand::addCard(Card card) {
	cards.push_back(card);
}

void Hand::hideCard(int index, bool hide) {
	if (index >= 0 && index < cards.size()) {
		cards[index].hidden = hide;
	}
}

void Hand::clear() {
	cards.clear();
}

bool Hand::hasAce() {
	for (const Card& card : cards) {
		if (card.rank == 14) {
			return true;
		}
	}

	return false;
}
