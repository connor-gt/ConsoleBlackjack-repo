#pragma once

class Deck {
public:
	Deck();
	void shuffle();
	Card deal();
	std::vector<Card> createCopy();

private:
	std::vector<Card> cards;
};
