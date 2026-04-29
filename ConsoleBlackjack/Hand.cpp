#include "Hand.h"

int Hand::evaluate() {
	return 0;
}

void Hand::render() {
	Card::render(cards);
}

void Hand::hit(Card card) {
	cards.push_back(card);
}
