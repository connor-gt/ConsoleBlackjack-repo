#include "Round.h"

void Round::playRound(Player& player, Dealer& dealer, Deck& deck) {
	player.hand.clear();
	dealer.hand.clear();

	for (int i = 0; i < 2; i++) {
		std::optional<Card> card = deck.deal();
		if (card) {
			player.hand.addCard(card.value());
		}

		card = deck.deal();
		if (card) {
			dealer.hand.addCard(card.value());
		}
	}

	// Hide the 2nd card in the dealer's hand
	dealer.hand.hideCard(1, true);

	std::cout << "\nDealer:\n";
	dealer.hand.render();

	std::cout << "\nPlayer:\n";
	player.hand.render();
}