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

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < Card::rowsToRender; j++) {
			std::cout << cards[i].render()[j] << std::endl;
		}
		std::cout << std::endl;
	}
}

void Deck::shuffle() {

}

Card Deck::deal() {
	return Card(3, "D");
}
